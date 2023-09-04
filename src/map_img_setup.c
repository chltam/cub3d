/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:29:09 by htam              #+#    #+#             */
/*   Updated: 2023/06/22 16:57:31 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_map_para(t_vars *vars)
{
	int	y;
	int	width;

	y = 0;
	width = 0;
	while (vars->cub->map[y])
	{
		if ((int)ft_strlen(vars->cub->map[y]) > width)
			width = ft_strlen(vars->cub->map[y]);
		y++;
	}
	vars->map_height = y + 1;
	vars->map_width = width + 1;
}

t_data	*map_img_setup(t_vars *vars)
{
	t_data	*map_img;

	get_map_para(vars);
	map_img = init_img(vars->mlx_ptr, NULL, vars->map_width * 64,
			vars->map_height * 64);
	return (map_img);
}

void	draw_blank(t_data *map_img, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			put_pix_to_img(map_img, j, i, GREY);
			j++;
		}
		i++;
	}
}

void	draw_tile(t_data *img, int x, int y, int color)
{
	int	map_x;
	int	map_y;
	int	i;
	int	j;

	map_x = x * 64;
	map_y = y * 64;
	i = 0;
	while (i < 63)
	{
		j = 0;
		while (j < 63)
		{
			put_pix_to_img(img, map_x + j, map_y + i, color);
			j++;
		}
		i++;
	}
}
