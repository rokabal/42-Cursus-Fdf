/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:20:56 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/22 13:19:08 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

static int	ft_arrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	get_info(int fd, t_map *map)
{
	int		i;
	char	*line;
	char	**values;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		free(line);
		if (!map->width)
		{
			values = ft_split(line, ' '); //not return right value for map 10-2.fdf
			i = -1;
			while (values[++i])
				printf("%s\n", values[i]);
		}
			map->width = ft_arrlen(values);
	}
}

void	read_map(t_map *map)
{
	int	fd;

	fd = open(map->name, O_RDONLY);
	get_info(fd, map);
	close(fd);
	printf("%d\n", map->height);
	printf("%d\n", map->width);
}
