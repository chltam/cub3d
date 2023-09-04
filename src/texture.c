/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:54:00 by cbadura           #+#    #+#             */
/*   Updated: 2023/06/23 15:17:32 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	put_texture_to_img(t_vars *v, t_data *img, t_lcoords *coords,
				t_rc *rc);
static void	get_horiz_tex(t_vars *v, t_data *img, t_rc *rc, char **src);
static void	get_vert_tex(t_vars *v, t_rc *rc, char **src);

void	draw_line_xpm(t_vars *v, t_data *img, t_lcoords *coords, t_rc *rc)
{
	float	scaler;
	float	delta;

	scaler = 0;
	rc->y_tex = 0;
	delta = UNIT_SIZE / v->wall_height;
	while (coords->y0 < coords->y1)
	{
		scaler += delta;
		rc->y_tex = (int)scaler;
		if (rc->y_tex >= 63)
			rc->y_tex = 63;
		put_texture_to_img(v, img, coords, rc);
		coords->y0++;
	}
}

static void	put_texture_to_img(t_vars *v, t_data *img, t_lcoords *coords,
		t_rc *rc)
{
	char	*dst;
	char	*src;
	int		color;

	color = 0;
	src = NULL;
	if (coords->x0 <= 0 || coords->y0 <= MAP_HEIGHT
		|| coords->x0 >= MAP_WIDTH || coords->y0 >= W_HEIGHT)
		return ;
	dst = img->addr + (coords->y0 * img->line_length
			+ coords->x0 * (img->bpp / 8));
	if (rc->hit_dir == NORTH || rc->hit_dir == SOUTH)
		get_horiz_tex(v, img, rc, &src);
	else if (rc->hit_dir == EAST || rc->hit_dir == WEST)
		get_vert_tex(v, rc, &src);
	else
	{
		color = BLACK;
		*(unsigned int *)dst = color;
		return ;
	}
	if (src)
		*(unsigned int *)dst = *(unsigned int *)src;
}

static void	get_horiz_tex(t_vars *v, t_data *img, t_rc *rc, char **src)
{
	if (rc->hit_dir == SOUTH)
	{
		*src = v->south_xpm->addr + (rc->y_tex * v->south_xpm->line_length
				+ (rc->hor_u_val % 64) * (img->bpp / 8));
	}
	else if (rc->hit_dir == NORTH)
	{
		*src = v->north_xpm->addr + (rc->y_tex * v->north_xpm->line_length
				+ (rc->hor_u_val % 64) * (img->bpp / 8));
	}
}

static void	get_vert_tex(t_vars *v, t_rc *rc, char **src)
{
	if (rc->hit_dir == EAST)
	{
		*src = v->east_xpm->addr + (rc->y_tex * v->east_xpm->line_length
				+ (rc->vert_u_val % 64) * (v->east_xpm->bpp / 8));
	}
	else if (rc->hit_dir == WEST)
	{
		*src = v->west_xpm->addr + (rc->y_tex * v->west_xpm->line_length
				+ (rc->vert_u_val % 64) * (v->west_xpm->bpp / 8));
	}
}
