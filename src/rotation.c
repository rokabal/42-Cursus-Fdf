/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:41:49 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/03 23:51:41 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(t_pix *new)
{
	t_pix	old;

	old = *new;
	new->x = (old.x - old.y) * cos(0.523599);
	new->y = -old.z + (old.x + old.y) * sin(523599);
}

void	parallel(t_pix *new)
{
	t_pix	old;

	old = *new;
	new->x = old.x - old.z * cos(0.785398);
	new->y = old.y - old.z * sin(0.785398);
}

void	rotation(t_pix *new, double alpha, double beta, double gamma)
{
	t_pix	old;

	old = *new;
	new->y = old.y * cos(alpha) + old.z * sin(alpha);
	new->z = -old.y * sin(alpha) + old.z * cos(alpha);
	new->x = old.x * cos(beta) + new->z * sin(beta);
	new->z = -old.x * sin(beta) + new->z * cos(beta);
	old = *new;
	new->x = old.x * cos(gamma) - old.y * sin(gamma);
	new->y = old.x * sin(gamma) + old.y * cos(gamma);
}

t_pix	transform(t_pix p, t_map *map)
{
	if (map->color && p.color == -1)
		p.color = 0xFFFFFF;
	if (!map->color || p.color == -1)
		p.color = init_color(map, p.z);
	p.x *= map->cam.zoom;
	p.y *= map->cam.zoom;
	p.z *= map->cam.zoom / map->cam.z_div;
	p.x -= map->width * map->cam.zoom / 2;
	p.y -= map->height * map->cam.zoom / 2;
	rotation(&p, map->cam.alpha, map->cam.beta, map->cam.gamma);
	if (map->cam.type == ISOMETRIC)
		isometric(&p);
	else if (map->cam.type == PARALLEL)
		parallel(&p);
	p.x += WIDTH / 2 + map->cam.offset_x;
	p.y += HEIGHT / 2 + map->cam.offset_y;
	return (p);
}
