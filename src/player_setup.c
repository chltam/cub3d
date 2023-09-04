/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:32:21 by htam              #+#    #+#             */
/*   Updated: 2023/06/21 22:32:43 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	set_player_xy(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->cub->map[y])
	{
		x = 0;
		while (vars->cub->map[y][x])
		{
			if (is_player(vars->cub->map[y][x]))
			{
				vars->player->y = y * 64 + 32;
				vars->player->x = x * 64 + 32;
				return (vars->cub->map[y][x]);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	set_player_pov(t_vars *vars, char c)
{
	if (c == 'N')
		vars->player->pov = M_PI * 3 / 2;
	if (c == 'E')
		vars->player->pov = 0;
	if (c == 'S')
		vars->player->pov = M_PI / 2;
	if (c == 'W')
		vars->player->pov = M_PI;
}

void	set_player_dxy(t_vars *vars)
{
	vars->player->dx = cos(vars->player->pov) * 2;
	vars->player->dy = sin(vars->player->pov) * 2;
}

int	player_setup(t_vars *vars)
{
	char	facing;

	vars->player = malloc(sizeof(*vars->player));
	if (!vars->player)
		return (-1);
	facing = set_player_xy(vars);
	set_player_pov(vars, facing);
	set_player_dxy(vars);
	return (0);
}
