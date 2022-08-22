/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:28:33 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/22 13:02:34 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define WIN_X 1920
# define WIN_Y 1080

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_int {
	int		x;
	int		y;
}	t_int;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			height;
	int			width;
	char		*name;
	t_int		**z;
}	t_map;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_line(t_img *img, t_int c1, t_int c2, int color);
void	read_map(t_map *map);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

#endif
