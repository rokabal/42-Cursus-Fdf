/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:16:04 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/03 08:59:43 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	light(int start, int end, double r)
{
	return ((int)((1 - r) * start + r * end));
}

static double	ratio(int start, int end, int pos)
{
	if (start == end)
		return (1.0);
	else
		return ((double)(pos - start) / (double)(end - start));
}

static int	color_mask(int color, char c)
{
	if (c == 'r')
		return ((color >> 16) & 0xFF);
	else if (c == 'g')
		return ((color >> 8) & 0xFF);
	else
		return (color & 0xFF);
}

int	gradient(t_pix p, t_pix start, t_pix end, t_pms pms)
{
	int		red;
	int		green;
	int		blue;
	double	r;

	if (p.color == end.color)
		return (p.color);
	if (pms.delta_x >= pms.delta_y)
		r = ratio(start.x, end.x, p.x);
	else
		r = ratio(start.y, end.y, p.y);
	red = light(color_mask(start.color, 'r'), color_mask(end.color, 'r'), r);
	green = light(color_mask(start.color, 'g'), color_mask(end.color, 'g'), r);
	blue = light(color_mask(start.color, 'b'), color_mask(end.color, 'b'), r);
	return ((red << 16) | (green << 8) | blue);
}

int	init_color(t_map *map, int z)
{
	double	percentage;

	percentage = ratio(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (map->colorset[0]);
	else if (percentage < 0.4)
		return (map->colorset[1]);
	else if (percentage < 0.6)
		return (map->colorset[2]);
	else if (percentage < 0.8)
		return (map->colorset[3]);
	else
		return (map->colorset[4]);
}
