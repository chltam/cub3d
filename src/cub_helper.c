/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:26:01 by htam              #+#    #+#             */
/*   Updated: 2023/06/26 10:11:45 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_atoi_lite(char *str)
{
	int	rei;

	rei = 0;
	if (*str == '\n')
		return (-1);
	while (*str && *str != '\n')
	{
		if (!ft_isdigit(*str))
			return (-1);
		rei = rei * 10 + *str - '0';
		str++;
		if (rei > 255)
			return (-1);
	}
	return (rei);
}

bool	is_info(char *tag)
{
	if (!tag)
		return (false);
	if (!ft_strcmp(tag, "NO") || !ft_strcmp(tag, "EA")
		|| !ft_strcmp(tag, "SO") || !ft_strcmp(tag, "WE"))
		return (true);
	if (!ft_strcmp(tag, "F") || !ft_strcmp(tag, "C"))
		return (true);
	return (false);
}

bool	is_player(char c)
{
	if (c == 'N' || c == 'E')
		return (true);
	if (c == 'S' || c == 'W')
		return (true);
	return (false);
}

int	max_row(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

bool	is_info_allset(t_cub *cub)
{
	int	n;

	n = 0;
	if (!cub->north_file || !cub->east_file)
		return (false);
	if (!cub->south_file || !cub->west_file)
		return (false);
	while (n < 3)
	{
		if (cub->floor[n] == -1 || cub->ceiling[n] == -1)
			return (false);
		n++;
	}
	return (true);
}
