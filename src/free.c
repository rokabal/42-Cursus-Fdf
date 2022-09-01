/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:48:19 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:46:53 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	free_grid(t_map *map)
{
	int	y;

	y = -1;
	while (++y < map->height)
		free(map->grid[y]);
	free(map->grid);
}

static void	free_mlx(t_map *map)
{
	if (map->img.img)
		mlx_destroy_image(map->mlx, map->img.img);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
}

void	free_map(t_map *map, char *err_msg, int err)
{
	if (map->fd && !ft_strncmp(err_msg, ERR_CLOSE, ft_strlen(ERR_CLOSE)))
		close(map->fd);
	if (map->grid)
		free_grid(map);
	free_mlx(map);
	if (err)
		exit_on_err(1, err_msg);
	else
		exit(EXIT_SUCCESS);
}

int	terminate(void *param)
{
	free_map((t_map *)param, "", 0);
	return (0);
}
