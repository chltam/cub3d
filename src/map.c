/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:28:34 by htam              #+#    #+#             */
/*   Updated: 2023/06/22 16:58:00 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->map_height - 1)
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
				draw_tile(vars->map_img, x, y, BLACK);
			else if (vars->map[y][x] == '0')
				draw_tile(vars->map_img, x, y, WHITE);
			else if (is_player(vars->map[y][x]))
			{
				vars->map[y][x] = '0';
				draw_tile(vars->map_img, x, y, WHITE);
			}
			x++;
		}
		y++;
	}
}

int	get_pixel_color(t_data *img, int x, int y)
{
	char	*color;

	color = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(unsigned int *)color);
}

t_lcoords	view_setup(t_vars *vars)
{
	t_lcoords	view;

	view.x0 = vars->player->x - 128;
	if (view.x0 < 0)
		view.x0 = 0;
	view.y0 = vars->player->y - 128;
	if (view.y0 < 0)
		view.y0 = 0;
	view.x1 = vars->player->x + 128;
	if (view.x1 > vars->map_width * 64)
		view.x1 = vars->map_width * 64;
	view.y1 = vars->player->y + 128;
	if (view.y1 > vars->map_height * 64)
		view.y1 = vars->map_height * 64;
	return (view);
}

void	draw_minimap(t_vars *vars)
{
	t_lcoords	view;
	int			color;
	int			mapx;
	int			y;
	int			x;

	y = 200;
	view = view_setup(vars);
	while (view.y0 < view.y1)
	{
		x = 250;
		mapx = view.x0;
		while (mapx < view.x1)
		{
			color = get_pixel_color(vars->map_img, mapx, view.y0);
			put_pix_to_img(vars->image, x, y, color);
			x++;
			mapx++;
		}
		y++;
		view.y0++;
	}
}
