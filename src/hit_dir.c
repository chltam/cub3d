/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:35:57 by cbadura           #+#    #+#             */
/*   Updated: 2023/06/23 15:13:04 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_hit_dir(t_rc *rc, t_vars *v)
{
	if (check_horiz_grid(rc, v))
	{
		if (v->map[rc->hor_map_y][rc->hor_map_x - 1] == '0'
			&& v->map[rc->hor_map_y][rc->hor_map_x] == '1')
			rc->hit_dir = WEST;
		else if (v->map[rc->hor_map_y][rc->hor_map_x - 1] == '1'
			&& v->map[rc->hor_map_y][rc->hor_map_x] == '0')
			rc->hit_dir = EAST;
	}
	else if (check_vert_grid(rc, v))
	{
		if (v->map[rc->vert_map_y - 1][rc->vert_map_x] == '1'
			&& v->map[rc->vert_map_y][rc->vert_map_x] == '0')
			rc->hit_dir = SOUTH;
		else if (v->map[rc->vert_map_y - 1][rc->vert_map_x] == '0'
			&& v->map[rc->vert_map_y][rc->vert_map_x] == '1')
			rc->hit_dir = NORTH;
	}
}
