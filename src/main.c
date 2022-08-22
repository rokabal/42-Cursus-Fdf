/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:05:04 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/21 21:26:26 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
// typedef struct s_map
// {
// 	void		*mlx;
// 	void		*win;
// 	t_img		img;
// 	int			height;
// 	int			width;
// 	char		*name;
// 	int			**map;
// 	int			color;
// }	t_map;

static void	init_map(t_map *map, char *name)
{
	static const t_map	empty_map;

	*map = empty_map;
	map->name = name;
}

static int	err_map(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	m;

	if (argc == 2)
	{
		if (err_map(argv[1]))
			write(1, "Error reading map", 17);
		else
		{
			init_map(&m, argv[1]);
			m.mlx = mlx_init();
			m.win = mlx_new_window(m.mlx, WIN_X, WIN_Y, m.name);
			m.img.img = mlx_new_image(m.win, m.width, m.height);
			m.img.addr = mlx_get_data_addr(m.img.img, &m.img.bits_per_pixel,
					&m.img.line_length, &m.img.endian);
			read_map(&m);
			mlx_put_image_to_window(m.mlx, m.win, m.img.img, 0, 0);
			//mlx_loop(m.mlx);
		}
	}
	write(1, "Usage: ./fdf MAP_FILE\n", 22);
}
