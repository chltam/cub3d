/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:27:43 by cbadura           #+#    #+#             */
/*   Updated: 2023/06/26 10:30:48 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_player(t_vars *vars, t_data *img, t_lcoords *coords);

void	put_pix_to_img_wild(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_vars *vars, t_data *img)
{
	t_lcoords	coords;

	draw_blank(vars->map_img, vars->map_width * 64, vars->map_height * 64);
	draw_map(vars);
	set_coords(&coords, vars, 10);
	draw_player(vars, vars->map_img, &coords);
	draw_scene(vars);
	rays_loop(vars);
	draw_minimap(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, img->img, 0, 0);
}

static void	draw_player(t_vars *vars, t_data *img, t_lcoords *coords)
{
	int	i;
	int	j;

	draw_line(img, coords, GREEN);
	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			if (vars->player->x + j >= 0 && vars->player->y + i >= 0
				&& vars->player->x + j < vars->map_width * 64
				&& vars->player->y + i < vars->map_height * 64)
				put_pix_to_img(img, vars->player->x + j,
					vars->player->y + i, RED);
			j++;
		}
		i++;
	}
}

void	put_pix_to_img(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
