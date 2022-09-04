/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:48:14 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/04 17:40:53 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	offset(int key, t_map *map)
{
	if (key == K_AR_L)
		map->cam.offset_x -= OFFSET;
	else if (key == K_AR_R)
		map->cam.offset_x += OFFSET;
	else if (key == K_AR_U)
		map->cam.offset_y -= OFFSET;
	else if (key == K_AR_D)
		map->cam.offset_y += OFFSET;
	update_image(map);
}

static void	rotate(int key, t_map *map)
{
	float	angle;

	angle = M_PI / 180;
	if (key == K_Z)
		map->cam.alpha += angle;
	else if (key == K_E)
		map->cam.alpha -= angle;
	else if (key == K_C)
		map->cam.beta += angle;
	else if (key == K_Q)
		map->cam.beta -= angle;
	else if (key == K_A)
		map->cam.gamma += angle;
	else if (key == K_D)
		map->cam.gamma -= angle;
	update_image(map);
}

static void	change_view(int key, t_map *map)
{
	if ((key == K_I) || (key == K_R))
		map->cam.type = ISOMETRIC;
	else if (key == K_P)
		map->cam.type = PLAN;
	map->cam.zoom = fmin(WIDTH / map->width / 2, HEIGHT / map->height / 2);
	map->cam.z_div = 10;
	map->cam.offset_x = 0;
	map->cam.offset_y = 0;
	map->cam.alpha = 0.0;
	map->cam.beta = 0.0;
	map->cam.gamma = 0.0;
	update_image(map);
}

static void	altitude_zoom(int key, t_map *map)
{
	if ((key == K_S) && map->cam.z_div < MAX_Z_DIV)
		map->cam.z_div += Z_DIV_STEP;
	else if ((key == K_W) && map->cam.z_div > MIN_Z_DIV)
		map->cam.z_div -= Z_DIV_STEP;
	else if ((key == K_N) && map->cam.zoom > 1)
		map->cam.zoom--;
	else if (key == K_M)
		map->cam.zoom++;
	update_image(map);
}

int	key_hook(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == K_ESC)
		free_map(map, "", 0);
	else if ((key == K_AR_L) || (key == K_AR_R) || (key == K_AR_U)
		|| (key == K_AR_D))
		offset(key, map);
	else if ((key == K_E) || (key == K_Z) || (key == K_C) || (key == K_Q)
		|| (key == K_A) || (key == K_D))
		rotate(key, map);
	else if ((key == K_R) || (key == K_I) || (key == K_P))
		change_view(key, map);
	else if ((key == K_S) || (key == K_W) || (key == K_N) || (key == K_M))
		altitude_zoom(key, map);
	else if ((key == K_J) || (key == K_K) || (key == K_L) || (key == K_X))
		change_colorset(key, map);
	return (0);
}
