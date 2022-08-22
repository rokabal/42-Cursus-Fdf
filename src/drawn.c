/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:20:19 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/22 11:56:05 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
}

static int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

static int	ft_sign(int a)
{
	if (a >= 0)
		return (1);
	return (-1);
}

/**
 * @brief Drawn a line connecting the coordinates c1 and c2 using
 * Bresenham's line algorithm
 * @param img image to drawn the line
 * @param c1 coordinate c1
 * @param c2 coordinate c2
 * @param color hex color
 */
void	draw_line(t_img *img, t_int c1, t_int c2, int color)
{
	t_int	d;
	t_int	s;
	t_int	err;

	d = (t_int){ft_abs(c2.x - c1.x), -ft_abs(c2.y - c1.y)};
	s = (t_int){ft_sign(c2.x - c1.x), ft_sign(c2.y - c1.y)};
	err = (t_int){d.x + d.y, 2 * (d.x + d.y)};
	while (1)
	{
		my_mlx_pixel_put(img, c1.x, c1.y, color); //verify the bounderis within the image
		if (c1.x == c2.x && c1.y == c2.y)
			break ;
		err.y = 2 * err.x;
		if (err.y >= d.y)
		{
			err.x += d.y;
			c1.x += s.x;
		}
		if (err.y <= d.x)
		{
			err.x += d.x;
			c1.y += s.y;
		}
	}
}
