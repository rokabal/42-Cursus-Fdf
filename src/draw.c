/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:20:19 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/03 23:06:14 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		dst = img->addr + (y * img->line_length
				+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	set_parameters(t_pms *pms, t_pix p1, t_pix p2)
{
	if (p2.x >= p1.x)
	{
		pms->delta_x = p2.x - p1.x;
		pms->sign_x = 1;
	}
	else
	{
		pms->delta_x = p1.x - p2.x;
		pms->sign_x = -1;
	}
	if (p2.y >= p1.y)
	{
		pms->delta_y = p2.y - p1.y;
		pms->sign_y = 1;
	}
	else
	{
		pms->delta_y = p1.y - p2.y;
		pms->sign_y = -1;
	}
	pms->offset = pms->delta_x - pms->delta_y;
	pms->error = 0;
}

/**
 * @brief Drawn a line connecting the position p1 and p2 using
 * Bresenham's line algorithm
 */
void	draw_line(t_map *map, t_pix p1, t_pix p2)
{
	t_pix	p;
	t_pms	pms;

	set_parameters(&pms, p1, p2);
	p = p1;
	while (p.x != p2.x || p.y != p2.y)
	{
		my_mlx_pixel_put(&(map->img), p.x, p.y, gradient(p, p1, p2, pms));
		pms.error = 2 * pms.offset;
		if (pms.error > -pms.delta_y)
		{
			pms.offset -= pms.delta_y;
			p.x += pms.sign_x;
		}
		if (pms.error < pms.delta_x)
		{
			pms.offset += pms.delta_x;
			p.y += pms.sign_y;
		}
	}
	my_mlx_pixel_put(&(map->img), p.x, p.y, gradient(p, p1, p2, pms));
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x < map->width - 1)
				draw_line(map, transform(map->grid[y][x], map),
					transform(map->grid[y][x + 1], map));
			if (y < map->height - 1)
				draw_line(map, transform(map->grid[y][x], map),
					transform(map->grid[y + 1][x], map));
		}
	}
}

void	update_image(t_map *map)
{
	if (map->img.img)
		mlx_destroy_image(map->mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &(map->img.bits_per_pixel),
			&(map->img.line_length), &(map->img.endian));
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	print_menu(map);
}
