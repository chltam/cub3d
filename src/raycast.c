/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:20:17 by htam              #+#    #+#             */
/*   Updated: 2023/06/26 11:47:34 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_ray(t_vars *v, int num_ray);
static void	set_rc(t_rc *rc, t_vars *v);

void	rays_loop(t_vars *v)
{
	float	orig_pov;
	float	dx;
	float	dy;
	int		n;

	dx = v->player->dx;
	dy = v->player->dy;
	orig_pov = v->player->pov;
	v->player->pov -= 0.5;
	n = NUM_RAYS;
	while (n > 0)
	{
		v->player->pov += RAD_BETW_RAYS;
		v->player->dx = cos(v->player->pov);
		v->player->dy = sin(v->player->pov);
		draw_ray(v, n);
		n--;
	}
	v->player->pov = orig_pov;
	v->player->dx = dx;
	v->player->dy = dy;
}
/*
	draw_line(v->map_img, &coords, RED);
	helper function to show ray
*/

static void	draw_ray(t_vars *v, int num_ray)
{
	t_lcoords	coords;
	t_rc		rc;
	float		ray;

	ray = 0;
	set_rc(&rc, v);
	while (check_vert_grid(&rc, v) && check_horiz_grid(&rc, v))
	{
		rc.hor_u_val = v->player->x + v->player->dx * ray;
		rc.vert_u_val = v->player->y + v->player->dy * ray;
		ray += 0.5;
		rc.hor_map_x = rc.hor_u_val / 64;
		rc.hor_map_y = (v->player->y + v->player->dy * ray) / 64;
		rc.vert_map_x = (v->player->x + v->player->dx * ray) / 64;
		rc.vert_map_y = rc.vert_u_val / 64;
	}
	get_hit_dir(&rc, v);
	set_coords(&coords, v, ray);
	draw_wall_slice(v, ray, num_ray, &rc);
}

static void	set_rc(t_rc *rc, t_vars *v)
{
	rc->hor_u_val = 1;
	rc->hor_map_x = (int)v->player->x / 64;
	rc->hor_map_y = (int)v->player->y / 64;
	rc->vert_u_val = 1;
	rc->vert_map_x = (int)v->player->x / 64;
	rc->vert_map_y = (int)v->player->y / 64;
	rc->hit_dir = DEFAULT;
}

/*
	reset rc calculation to closest factor of 64 (below current value):
	rc->hor_u_val = v->player_x;
	rc->hor_offset = rc->hor_u_val % 64;
	rc->hor_u_val = rc->hor_u_val - rc->hor_offset;
	rc->vert_u_val = v->player_y + v->player_dy;
	rc->vert_offset = rc->vert_u_val % 64;
	rc->vert_u_val = rc->vert_u_val - rc->vert_offset;
*/

int	check_vert_grid(t_rc *rc, t_vars *v)
{
	if ((rc->hor_u_val % 64) != 0
		|| ((v->map[rc->hor_map_y][rc->hor_map_x] == '0')
		&& (v->map[rc->hor_map_y][rc->hor_map_x - 1] == '0')))
	{
		return (1);
	}
	else
		return (0);
}

int	check_horiz_grid(t_rc *rc, t_vars *v)
{
	if ((rc->vert_u_val % 64 != 0)
		|| ((v->map[rc->vert_map_y][rc->vert_map_x] == '0')
		&& (v->map[rc->vert_map_y - 1][rc->vert_map_x] == '0')))
	{
		return (1);
	}
	else
		return (0);
}
