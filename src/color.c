/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:16:04 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/01 12:03:28 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	linear_change(int start, int end, double r)
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

static int	color_bitmask(int color, char c)
{
	if (c == 'r')
		return ((color >> 16) & 0xFF);
	else if (c == 'g')
		return ((color >> 8) & 0xFF);
	else if (c == 'b')
		return (color & 0xFF);
	else
		return (-1);
}

int	gradient(t_pix p, t_pix start, t_pix end, t_pms pms)
{
	int		red;
	int		green;
	int		blue;
	double	r;

	if (p.color)
		return (p.color);
	if (pms.delta_x >= pms.delta_y)
		r = ratio(start.x, end.x, p.x);
	else
		r = ratio(start.y, end.y, p.y);
	red = linear_change(color_bitmask(start.color, 'r'),
			color_bitmask(end.color, 'r'), r);
	green = linear_change(color_bitmask(start.color, 'g'),
			color_bitmask(end.color, 'g'), r);
	blue = linear_change(color_bitmask(start.color, 'b'),
			color_bitmask(end.color, 'b'), r);
	return ((red << 16) | (green << 8) | blue);
}

int	set_color(t_map *map, int z)
{
	double	r;

	r = ratio
}
