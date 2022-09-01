/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:28:33 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/01 00:19:15 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../inc/keycode_linux.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*
**	Available projections and some informations
*/

# define ISOMETRIC		0
# define PARALLEL		1
# define OFFSET			10
# define ANGLE_RAD		0.05
# define ALTITUDE		1
# define MIN_ALTITUDE	1
# define MAX_ALTITUDE	20
# define WIDTH			1280
# define HEIGHT			720
# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17

/*
**	Error messages
*/

# define ERR_USAGE		"Usage: ./fdf [map.fdf]\n"
# define ERR_OPEN		"Error: Can't open file.\n"
# define ERR_CLOSE		"Error: Can't close file.\n"
# define ERR_SPLIT		"Error: Can't retrieve all points.\n"
# define ERR_WIDTH		"Error: Map width isn't the same all rows.\n"
# define ERR_FORMAT		"Error: Incorrect row format.\n"
# define ERR_MALLOC		"Error: Can't allocate memory.\n"
# define ERR_FILENAME	"Error: Wrong filename.\n"
# define ERR_EMPTY_ROW	"Error: Empty row within the file.\n"
# define ERR_EMPTY_FILE	"Error: Empty file.\n"

/*
 **	Pixel details
 */

typedef struct s_pix {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_pix;

/*
 **	MLX image details 
 */
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/*
 **	 Bresenham's line algorithm parameters
 */

typedef struct s_pms
{
	int	sign_x;
	int	sign_y;
	int	delta_x;
	int	delta_y;
	int	offset;
	int	error;
}	t_pms;

/*
 **	Camera view details 
 */

typedef struct s_cam
{
	int		type;
	int		altitude;
	int		zoom;
	int		offset_x;
	int		offset_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*name;
	int		fd;
	t_cam	cam;
	t_img	img;
	t_pix	**grid;
}	t_map;

void	read_map(t_map *map);
void	draw_map(t_map *map);
void	draw_line(t_map *map, t_pix p1, t_pix p2);
void	free_map(t_map *map, char *err_msg, int err);
int		gradient(t_pix p, t_pix start, t_pix end, t_pms pms);
int		key_hook(int key, void *param);
int		terminate(void *param);
t_pix	transform(t_pix p, t_map *map);

#endif
