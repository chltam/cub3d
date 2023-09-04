/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:24:16 by htam              #+#    #+#             */
/*   Updated: 2023/06/21 21:53:56 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	valid_info(t_cub *cub);
static int	basic_map_check(char **map);
static int	map_check(char **map);
static int	check_around(char **map, int y, int x);

int	valid_cub(t_cub *cub)
{
	if (valid_info(cub) == -1)
		return (-1);
	if (!cub->map)
		return (-1);
	if (basic_map_check(cub->map) == -1)
		return (-1);
	if (map_check(cub->map) == -1)
		return (-1);
	return (0);
}

static int	valid_info(t_cub *cub)
{
	int		n;
	int		fd;
	char	*files[4];

	n = 0;
	files[0] = cub->north_file;
	files[1] = cub->east_file;
	files[2] = cub->south_file;
	files[3] = cub->west_file;
	while (n < 4)
	{
		fd = open(files[n], O_RDONLY);
		if (fd == -1)
			return (ft_printf("Error\nOpen texture failed\n"), -1);
		close(fd);
		n++;
	}
	n = 0;
	while (n < 3)
	{
		if (cub->floor[n] == -1 || cub->ceiling[n] == -1)
			return (ft_printf("Error\nRGB\n"), -1);
		n++;
	}
	return (0);
}

static int	basic_map_check(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
		y++;
	if (y < 3)
		return (-1);
	while (map[0][x])
	{
		if (map[0][x] != '1' && map[0][x] != ' ')
			return (ft_printf("Error\nMap\n"), -1);
		x++;
	}
	x = 0;
	while (map[y - 1][x])
	{
		if (map[y - 1][x] != '1' && map[y - 1][x] != ' ')
			return (ft_printf("Error\nMap\n"), -1);
		x++;
	}
	return (0);
}

static int	map_check(char **map)
{
	int	max_y;
	int	y;
	int	x;

	max_y = max_row(map);
	y = 1;
	while (y < max_y)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || is_player(map[y][x]))
			{
				if (check_around(map, y, x) == -1)
					return (ft_printf("Error\nMap\n"), -1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_around(char **map, int y, int x)
{
	if (x == 0)
		return (-1);
	if (x + 1 > (int)ft_strlen(map[y - 1])
		|| x + 1 > (int)ft_strlen(map[y + 1]))
		return (-1);
	if (map[y][x - 1] == ' ' || map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
		return (-1);
	if (!map[y][x + 1])
		return (-1);
	return (0);
}
