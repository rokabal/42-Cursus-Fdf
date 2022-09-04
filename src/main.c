/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:05:04 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/03 23:43:47 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_map(t_map *map, char *name)
{
	static const t_map	empty_map;
	t_pix				p;

	*map = empty_map;
	map->name = name;
	map->cam.z_div = 10.0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, map->name);
	pf_set(map);
	read_map(map);
	map->cam.zoom = fmin(WIDTH / map->width / 2, HEIGHT / map->height / 2);
	p.y = -1;
	while (++p.y < map->height)
	{
		p.x = -1;
		while (++p.x < map->width)
		{
			if (map->grid[p.y][p.x].z < map->z_min)
				map->z_min = map->grid[p.y][p.x].z;
			if (map->grid[p.y][p.x].z > map->z_max)
				map->z_max = map->grid[p.y][p.x].z;
		}
	}
}

static int	valid_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 4)
		return (0);
	if (ft_strncmp(&filename[i - 4], ".fdf", 5))
		return (0);
	return (1);
}

void	print_menu(t_map *map)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = map->mlx;
	win = map->win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: N/M");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: W/S");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis: E/Z");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis: C/Q");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis: A/D");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Colorset:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Gray to Red: J");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Blue to Yellow: K");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Pink Foam: L");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Reverse: X");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P");
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit_on_err(1, ERR_USAGE);
	if (!valid_filename(argv[1]))
		exit_on_err(1, ERR_FILENAME);
	init_map(&map, argv[1]);
	update_image(&map);
	mlx_hook(map.win, ON_KEYDOWN, 1L << 0, key_hook, &map);
	mlx_hook(map.win, ON_DESTROY, 0, terminate, &map);
	mlx_loop(map.mlx);
}
