/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:25:45 by cbadura           #+#    #+#             */
/*   Updated: 2023/06/22 17:49:47 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	*v;

	if (argc != 2)
		return (ft_printf("Error\nargc\n"), -1);
	v = init_vars(argv[1]);
	if (!v)
		return (-1);
	draw(v, v->image);
	mlx_hook(v->win_ptr, MotionNotify, PointerMotionMask, mouse_event, v);
	mlx_mouse_hide(v->mlx_ptr, v->win_ptr);
	mlx_hook(v->win_ptr, DestroyNotify, StructureNotifyMask, close_cross, v);
	mlx_hook(v->win_ptr, KeyPress, KeyPressMask, key_events, v);
	mlx_loop(v->mlx_ptr);
	return (0);
}
