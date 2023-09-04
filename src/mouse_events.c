/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:49:14 by htam              #+#    #+#             */
/*   Updated: 2023/06/22 17:49:15 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mouse_move_left(t_vars *vars)
{
	vars->player->pov -= 0.05;
	if (vars->player->pov < 0)
		vars->player->pov += 2 * M_PI;
	vars->player->dx = cos(vars->player->pov) * 2;
	vars->player->dy = sin(vars->player->pov) * 2;
}

void	mouse_move_right(t_vars *vars)
{
	vars->player->pov += 0.05;
	if (vars->player->pov < 0)
		vars->player->pov += 2 * M_PI;
	vars->player->dx = cos(vars->player->pov) * 2;
	vars->player->dy = sin(vars->player->pov) * 2;
}

int	mouse_event(int x, int y, void	*param)
{
	t_vars		*v;
	static int	last_x;

	v = (t_vars *)param;
	if (x < 10)
		mlx_mouse_move(v->mlx_ptr, v->win_ptr, 710, y);
	if (x > 710)
		mlx_mouse_move(v->mlx_ptr, v->win_ptr, 10, y);
	if (x < last_x)
		mouse_move_left(v);
	if (x > last_x)
		mouse_move_right(v);
	if (x + 300 > last_x || x - 300 < last_x)
		last_x = x;
	draw(v, v->image);
	return (0);
}

int	close_esc(int keycode, t_vars *v)
{
	if (keycode == ESC && v)
	{
		free_vars(v);
		exit(1);
	}
	return (0);
}

int	close_cross(t_vars *v)
{
	free_vars(v);
	exit(1);
}
