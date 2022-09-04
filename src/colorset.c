/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:51:55 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/03 09:20:57 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	gtr_set(t_map *map)
{
	map->colorset[0] = GTR_1;
	map->colorset[1] = GTR_2;
	map->colorset[2] = GTR_3;
	map->colorset[3] = GTR_4;
	map->colorset[4] = GTR_5;
}

static void	bty_set(t_map *map)
{
	map->colorset[0] = BTY_1;
	map->colorset[1] = BTY_2;
	map->colorset[2] = BTY_3;
	map->colorset[3] = BTY_4;
	map->colorset[4] = BTY_5;
}

void	pf_set(t_map *map)
{
	map->colorset[0] = PF_1;
	map->colorset[1] = PF_2;
	map->colorset[2] = PF_3;
	map->colorset[3] = PF_4;
	map->colorset[4] = PF_5;
}

static void	reverse_set(t_map *map)
{
	int	tmp;

	tmp = map->colorset[0];
	map->colorset[0] = map->colorset[4];
	map->colorset[4] = tmp;
	tmp = map->colorset[1];
	map->colorset[1] = map->colorset[3];
	map->colorset[3] = tmp;
}

void	change_colorset(int key, t_map *map)
{
	if (key == K_J)
		gtr_set(map);
	else if (key == K_K)
		bty_set(map);
	else if (key == K_L)
		pf_set(map);
	else if (key == K_X)
		reverse_set(map);
	update_image(map);
}
