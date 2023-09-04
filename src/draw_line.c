/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:49:26 by htam              #+#    #+#             */
/*   Updated: 2023/06/22 17:49:28 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	line_alg(t_data *img, t_line_vars *lvars,
				t_lcoords *coords, int color);

void	draw_line(t_data *img, t_lcoords *coords, int color)
{
	t_line_vars	*lvars;

	lvars = malloc(sizeof(t_line_vars));
	ft_memset(lvars, 0, sizeof(t_line_vars));
	lvars->dx = abs(coords->x1 - coords->x0);
	if (coords->x0 < coords->x1)
		lvars->sx = 1;
	else
		lvars->sx = -1;
	lvars->dy = abs(coords->y1 - coords->y0);
	if (coords->y0 < coords->y1)
		lvars->sy = 1;
	else
		lvars->sy = -1;
	if (lvars->dx > lvars->dy)
		lvars->err = lvars->dx / 2;
	else
		lvars->err = -lvars->dy / 2;
	line_alg(img, lvars, coords, color);
	free(lvars);
}

static void	line_alg(t_data *img, t_line_vars *lvars,
		t_lcoords *coords, int color)
{
	while (1)
	{
		put_pix_to_img(img, coords->x0, coords->y0, color);
		if (coords->x0 == coords->x1 && coords->y0 == coords->y1)
			break ;
		lvars->e2 = lvars->err;
		if (lvars->e2 > -lvars->dx)
		{
			lvars->err -= lvars->dy;
			coords->x0 += lvars->sx;
		}
		if (lvars->e2 < lvars->dy)
		{
			lvars->err += lvars->dx;
			coords->y0 += lvars->sy;
		}
	}
}

void	set_coords(t_lcoords *coords, t_vars *vars, int factor)
{
	coords->x0 = vars->player->x;
	coords->y0 = vars->player->y;
	coords->x1 = vars->player->x + vars->player->dx * factor;
	coords->y1 = vars->player->y + vars->player->dy * factor;
}

void	set_wall_coords(t_lcoords *coords, int wall_top, int wall_btm,
	int num_ray)
{
	coords->x0 = GAME_WIDTH / 2 - num_ray + 400; 
	coords->y0 = wall_top + 512 + 150;
	coords->x1 = GAME_WIDTH / 2 - num_ray + 400;
	coords->y1 = wall_btm + 512 + 150;
}
