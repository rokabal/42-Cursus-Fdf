/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:48:14 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/30 20:44:33 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	offset(int key, t_map *map)
{
	if (key == K_AR_L)
		map->cam.offset_x -= OFFSET;
	if (key == K_AR_R)
		map->cam.offset_x += OFFSET;
	if (key == K_AR_U)
		map->cam.offset_y -= OFFSET;
	if (key == K_AR_D)
		map->cam.offset_y += OFFSET;
}

static void	rotate(int key, t_map *map)
{
	if (key == K_E)
		map->cam.alpha -= ANGLE_RAD;
	else if (key == K_Z)
		map->cam.alpha += ANGLE_RAD;
	else if (key == K_C)
		map->cam.beta -= ANGLE_RAD;
	else if (key == K_Q)
		map->cam.beta += ANGLE_RAD;
	else if (key == K_A)
		map->cam.gamma -= ANGLE_RAD;
	else if (key == K_D)
		map->cam.gamma += ANGLE_RAD;
}

static void	change_view(int key, t_map *map)
{
	if (key == K_I)
		map->cam.type = ISOMETRIC;
	else if (key == K_P)
		map->cam.type = PARALLEL;
	map->cam.zoom = fmin(WIDTH / map->width / 2, HEIGHT / map->height / 2);
	map->cam.altitude = 20;
	map->cam.offset_x = 0;
	map->cam.offset_y = 0;
	map->cam.alpha = 0.0;
	map->cam.beta = 0.0;
	map->cam.gamma = 0.0;
}

// else if ((key == K_9) && map->cam.zoom > 0)
// 	map->cam.zoom--;
// else if (key == K_0)
// 	map->cam.zoom++;
int	key_hook(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	mlx_destroy_image(map->mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &(map->img.bits_per_pixel),
			&(map->img.line_length), &(map->img.endian));
	if (key == K_ESC)
		free_map(map, "", 0);
	else if ((key == K_AR_L) || (key == K_AR_R) || (key == K_AR_R)
		|| (key == K_AR_D))
		offset(key, map);
	else if ((key == K_E) || (key == K_Z) || (key == K_C) || (key == K_Q)
		|| (key == K_A) || (key == K_D))
		rotate(key, map);
	else if ((key == K_R) || (key == K_I) || (key == K_P))
		change_view(key, map);
	else if ((key == K_W) && map->cam.altitude < MAX_ALTITUDE)
		map->cam.altitude += ALTITUDE;
	else if ((key == K_S) && map->cam.altitude > MIN_ALTITUDE)
		map->cam.altitude -= ALTITUDE;
	else if ((key == K_N) && map->cam.zoom > 0)
		map->cam.zoom--;
	else if (key == K_M)
		map->cam.zoom++;
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}
