/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:05:04 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:55:49 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_map(t_map *map, char *name)
{
	static const t_map	empty_map;

	*map = empty_map;
	map->name = name;
}

static void	setup_map(t_map *map)
{
	map->cam.zoom = fmin(WIDTH / map->width / 2, HEIGHT / map->height / 2);
	map->cam.altitude = 20.0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit_on_err(1, ERR_USAGE);
	init_map(&map, argv[1]);
	read_map(&map);
	setup_map(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WIDTH, HEIGHT, map.name);
	map.img.img = mlx_new_image(map.mlx, WIDTH, HEIGHT);
	map.img.addr = mlx_get_data_addr(map.img.img, &(map.img.bits_per_pixel),
			&(map.img.line_length), &(map.img.endian));
	draw_map(&map);
	mlx_put_image_to_window(map.mlx, map.win, map.img.img, 0, 0);
	mlx_key_hook(map.win, key_hook, &map);
	// mlx_hook(map.win, ON_KEYUP, 0, key_release, &map);
	// mlx_hook(map.win, ON_MOUSEDOWN, 0, mouse_press, &map);
	// mlx_hook(map.win, ON_MOUSEUP, 0, mouse_release, &map);
	// mlx_hook(map.win, ON_MOUSEMOVE, 0, mouse_move, &map);
	mlx_hook(map.win, ON_DESTROY, 0, terminate, &map);
	mlx_loop(map.mlx);
}
