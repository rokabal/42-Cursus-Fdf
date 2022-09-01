/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:20:56 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:30:10 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	line_width(char **str)
{
	int	i;

	i = 0;
	while (str[i] && *str[i] != '\n')
		i++;
	return (i);
}

static void	get_size(t_map *map)
{
	int		width;
	char	*line;
	char	**values;

	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		map->height++;
		values = ft_split(line, ' ');
		free(line);
		if (!values)
			free_map(map, ERR_SPLIT, 1);
		width = line_width(values);
		if (!map->width)
			map->width = width;
		free_split(values);
		if (width != map->width)
			free_map(map, ERR_WIDTH, 1);
	}
	if (!map->height)
		free_map(map, ERR_EMPTY_FILE, 1);
}

static int	get_color(char *value)
{
	int	i;
	int	nbr;

	i = 0;
	while (value[i] && value[i] != 'x')
		i++;
	if (!value[i])
		return (0);
	nbr = 0;
	while (value[++i])
	{
		if (ft_isdigit(value[i]))
			nbr = 16 * nbr + (value[i] - '0');
		else if (value[i] >= 'a' && value[i] <= 'f')
			nbr = 16 * nbr + (value[i] - 'a' + 10);
		else if (value[i] >= 'A' && value[i] <= 'F')
			nbr = 16 * nbr + (value[i] - 'A' + 10);
		else
			return (0);
	}
	return (nbr);
}

static void	get_pos(t_map *map)
{
	char	*line;
	char	**values;
	t_pix	p;

	p = (t_pix){0, 0, 0, 0};
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		values = ft_split(line, ' ');
		free(line);
		if (!values)
			free_map(map, ERR_SPLIT, 1);
		p.x = -1;
		while (++p.x < map->width)
			map->grid[p.y][p.x] = (t_pix){p.x, p.y, ft_atoi(values[p.x]),
				get_color(values[p.x])};
		free_split(values);
		p.y++;
	}
}

void	read_map(t_map *map)
{
	int	i;

	map->fd = open(map->name, O_RDONLY);
	if (map->fd < 0)
		exit_on_err(1, ERR_OPEN);
	get_size(map);
	if (close(map->fd))
		free_map(map, ERR_CLOSE, 1);
	map->grid = malloc(sizeof(t_pix *) * map->height);
	if (!map->grid)
		exit_on_err(1, ERR_MALLOC);
	i = -1;
	while (++i < map->height)
	{
		map->grid[i] = malloc(sizeof(t_pix) * map->width);
		if (!map->grid[i])
			free_map(map, ERR_MALLOC, 1);
	}
	map->fd = open(map->name, O_RDONLY);
	if (map->fd < 0)
		exit_on_err(1, ERR_OPEN);
	get_pos(map);
	if (close(map->fd))
		free_map(map, ERR_CLOSE, 1);
	map->fd = 0;
}
