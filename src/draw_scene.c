/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:36:28 by cbadura           #+#    #+#             */
/*   Updated: 2023/06/22 11:36:30 by cbadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_ceiling(t_vars *vars, int i, int j);
static void	draw_floor(t_vars *vars, int i, int j);

void	draw_scene(t_vars *vars)
{
	int	i;
	int	j;

	i = 512;
	while (i < 512 + 512 / 2)
	{
		j = 230;
		draw_ceiling(vars, i, j);
		i++;
	}
	while (i < W_HEIGHT)
	{
		j = 230;
		draw_floor(vars, i, j);
		i++;
	}
}

static void	draw_ceiling(t_vars *vars, int i, int j)
{
	int	color;

	while (j < MAP_WIDTH - 170)
	{
		color = (vars->cub->ceiling[0] << 16)
			+ (vars->cub->ceiling[1] << 8) + vars->cub->ceiling[2];
		put_pix_to_img(vars->image, j, i, color);
		j++;
	}
}

static void	draw_floor(t_vars *vars, int i, int j)
{
	int	color;

	while (j < MAP_WIDTH - 170)
	{
		color = (vars->cub->floor[0] << 16)
			+ (vars->cub->floor[1] << 8) + vars->cub->floor[2];
		put_pix_to_img(vars->image, j, i, color);
		j++;
	}
}

void	draw_wall_slice(t_vars *v, double ray, int num_ray, t_rc *rc)
{
	t_lcoords	wall_coords;
	int			wall_top;
	int			wall_btm;
	float		dist_corr_beta;

	if (num_ray > NUM_RAYS / 2)
	{
		dist_corr_beta = (NUM_RAYS / 2 - (NUM_RAYS - num_ray))
			* RAD_BETW_RAYS;
	}
	else
		dist_corr_beta = (NUM_RAYS / 2 - num_ray) * RAD_BETW_RAYS;
	ray = ray * cos(dist_corr_beta);
	v->wall_height = UNIT_SIZE / ray * DIST_TO_PLANE;
	v->tx_scale = v->wall_height / UNIT_SIZE;
	wall_top = 100 - v->wall_height / 2;
	wall_btm = wall_top + v->wall_height;
	set_wall_coords(&wall_coords, wall_top, wall_btm, num_ray);
	draw_line_xpm(v, v->image, &wall_coords, rc);
}
