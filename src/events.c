/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:56:05 by cbadura           #+#    #+#             */
/*   Updated: 2023/06/22 17:37:11 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	move(int keycode, t_vars *v);

int	key_events(int keycode, t_vars *v)
{
	if (v)
	{
		if (keycode == 65307)
			close_esc(keycode, v);
		if (keycode == W_KEY || keycode == A_KEY
			|| keycode == S_KEY || keycode == D_KEY
			|| keycode == LEFT || keycode == RIGHT)
			move(keycode, v);
	}
	return (0);
}

void	wall_check_front(t_vars *v)
{
	int	next_x;
	int	next_y;

	next_x = (v->player->x + v->player->dx) / 64;
	next_y = (v->player->y + v->player->dy) / 64;
	if ((int)(v->player->x + v->player->dx) % 64 == 0)
	{
		if (v->map[next_y][next_x - 1] == '1' || v->map[next_y][next_x] == '1')
			return ;
	}
	if ((int)(v->player->y + v->player->dy) % 64 == 0)
	{
		if (v->map[next_y - 1][next_x] == '1' || v->map[next_y][next_x] == '1')
			return ;
	}
	if (v->map[next_y][next_x] == '1')
		return ;
	v->player->x = v->player->x + v->player->dx;
	v->player->y = v->player->y + v->player->dy;
}

void	wall_check_back(t_vars *v)
{
	int	next_x;
	int	next_y;

	next_x = (v->player->x - v->player->dx) / 64;
	next_y = (v->player->y - v->player->dy) / 64;
	if ((int)(v->player->x - v->player->dx) % 64 == 0)
	{
		if (v->map[next_y][next_x - 1] == '1' || v->map[next_y][next_x] == '1')
			return ;
	}
	if ((int)(v->player->y - v->player->dy) % 64 == 0)
	{
		if (v->map[next_y - 1][next_x] == '1' || v->map[next_y][next_x] == '1')
			return ;
	}
	if (v->map[next_y][next_x] == '1')
		return ;
	v->player->x = v->player->x - v->player->dx;
	v->player->y = v->player->y - v->player->dy;
}

static int	move(int keycode, t_vars *v)
{
	if (keycode == A_KEY)
	{
		v->player->pov -= 0.1;
		if (v->player->pov < 0)
			v->player->pov += 2 * M_PI;
		v->player->dx = cos(v->player->pov) * 2;
		v->player->dy = sin(v->player->pov) * 2;
	}
	if (keycode == D_KEY)
	{
		v->player->pov += 0.1;
		if (v->player->pov > 2 * M_PI)
			v->player->pov -= 2 * M_PI;
		v->player->dx = cos(v->player->pov) * 2;
		v->player->dy = sin(v->player->pov) * 2;
	}
	if (keycode == W_KEY)
		wall_check_front(v);
	if (keycode == S_KEY)
		wall_check_back(v);
	draw(v, v->image);
	return (0);
}
