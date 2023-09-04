/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:58:31 by htam              #+#    #+#             */
/*   Updated: 2023/06/21 21:58:44 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_2d(char **str)
{
	int	n;

	n = 0;
	if (!str)
		return ;
	while (str[n])
	{
		free(str[n]);
		n++;
	}
	free(str);
}

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->north_file)
		free(cub->north_file);
	if (cub->east_file)
		free(cub->east_file);
	if (cub->south_file)
		free(cub->south_file);
	if (cub->west_file)
		free(cub->west_file);
	if (cub->map)
		free_2d(cub->map);
	free(cub);
}

void	free_img_data(void *mlx_ptr, t_data *img)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(mlx_ptr, img->img);
	free(img);
}

void	free_img(t_vars *vars)
{
	if (vars->image)
		free_img_data(vars->mlx_ptr, vars->image);
	if (vars->map_img)
		free_img_data(vars->mlx_ptr, vars->map_img);
	if (vars->north_xpm)
		free_img_data(vars->mlx_ptr, vars->north_xpm);
	if (vars->east_xpm)
		free_img_data(vars->mlx_ptr, vars->east_xpm);
	if (vars->south_xpm)
		free_img_data(vars->mlx_ptr, vars->south_xpm);
	if (vars->west_xpm)
		free_img_data(vars->mlx_ptr, vars->west_xpm);
}

void	free_vars(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free_img(vars);
	free_cub(vars->cub);
	free(vars->player);
	if (vars->mlx_ptr)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
	}
	free(vars);
}
