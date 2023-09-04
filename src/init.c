/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:29:46 by htam              #+#    #+#             */
/*   Updated: 2023/06/21 22:31:25 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	mlx_setup(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (-1);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr,
			W_WIDTH, W_HEIGHT, "cub3d");
	if (!vars->win_ptr)
		return (-1);
	return (0);
}

t_data	*init_img(void *mlx_ptr, char *path, int width, int height)
{
	t_data	*img;

	img = malloc(sizeof(*img));
	if (!img)
		return (NULL);
	if (path)
		img->img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	else
		img->img = mlx_new_image(mlx_ptr, width, height);
	if (!img->img)
		return (free(img), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	return (img);
}

static int	image_setup(t_vars *vars)
{
	vars->image = init_img(vars->mlx_ptr, NULL, W_WIDTH, W_HEIGHT);
	if (!vars->image)
		return (-1);
	vars->map_img = map_img_setup(vars);
	if (!vars->map_img)
		return (-1);
	vars->north_xpm = init_img(vars->mlx_ptr, vars->cub->north_file, 0, 0);
	vars->east_xpm = init_img(vars->mlx_ptr, vars->cub->east_file, 0, 0);
	vars->south_xpm = init_img(vars->mlx_ptr, vars->cub->south_file, 0, 0);
	vars->west_xpm = init_img(vars->mlx_ptr, vars->cub->west_file, 0, 0);
	if (!vars->north_xpm || !vars->east_xpm
		||!vars->south_xpm || !vars->west_xpm)
		return (-1);
	return (0);
}

t_vars	*init_vars(char *file)
{
	t_vars	*vars;

	vars = malloc(sizeof(*vars));
	if (!vars)
		return (NULL);
	ft_memset(vars, 0, sizeof(*vars));
	vars->cub = cub_parse(file);
	if (!vars->cub)
		return (free_vars(vars), NULL);
	vars->map = vars->cub->map;
	if (mlx_setup(vars) == -1)
		return (free_vars(vars), NULL);
	if (image_setup(vars) == -1)
		return (free_vars(vars), NULL);
	if (player_setup(vars) == -1)
		return (free_vars(vars), NULL);
	return (vars);
}
