/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_readset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:43:46 by htam              #+#    #+#             */
/*   Updated: 2023/06/22 19:31:22 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	read_info(char *str, t_cub *cub);
static void	set_texture_file(char **arr, t_cub *cub);
static void	set_floor_ceiling(char **arr, t_cub *cub);
static char	**map_split(char *map_1d);

int	read_cub_file(int cub_fd, t_cub *cub)
{
	char	*str;
	int		check;
	char	*map_1d;

	str = get_next_line(cub_fd);
	check = 0;
	map_1d = ft_strdup("");
	while (str)
	{
		if (is_info_allset(cub))
			map_1d = ft_strjoin_free_s1(map_1d, str);
		if (!is_info_allset(cub))
			check += read_info(str, cub);
		free(str);
		str = get_next_line(cub_fd);
	}
	check += map_1d_check(map_1d);
	if (check == 0)
		cub->map = map_split(map_1d);
	if (check < 0)
		return (free(map_1d), ft_printf("Error\nWrong Format\n"), check);
	return (check);
}

static char	**map_split(char *map_1d)
{
	char	**map;
	int		n;

	map_1d = ft_strjoin_free_s2(" \n", map_1d);
	map = ft_split(map_1d, '\n');
	n = 0;
	while (map[n])
	{
		map[n] = ft_strjoin_free_s2(" ", map[n]);
		n++;
	}
	free(map_1d);
	return (map);
}

static int	read_info(char *str, t_cub *cub)
{
	char	**arr;

	if (str[0] == '\n')
		return (0);
	arr = ft_split(str, ' ');
	if (is_info(arr[0]) && arr[1] && !arr[2])
		set_texture_file(arr, cub);
	else
		return (free_2d(arr), -1);
	free_2d(arr);
	return (0);
}

static void	set_texture_file(char **arr, t_cub *cub)
{
	char	**target;

	if (!ft_strcmp(arr[0], "NO"))
		target = &cub->north_file;
	else if (!ft_strcmp(arr[0], "EA"))
		target = &cub->east_file;
	else if (!ft_strcmp(arr[0], "SO"))
		target = &cub->south_file;
	else if (!ft_strcmp(arr[0], "WE"))
		target = &cub->west_file;
	else if (!ft_strcmp(arr[0], "F") || !ft_strcmp(arr[0], "C"))
		return (set_floor_ceiling(arr, cub));
	else
		return ;
	*target = ft_substr(arr[1], 0, ft_strlen(arr[1]) - 1);
}

static void	set_floor_ceiling(char **arr, t_cub *cub)
{
	int		n;
	char	**color;
	int		*target;

	n = 0;
	color = ft_split(arr[1], ',');
	if (!ft_strcmp(arr[0], "F"))
		target = cub->floor;
	else
		target = cub->ceiling;
	while (n < 3 && color[n])
	{
		target[n] = ft_atoi_lite(color[n]);
		n++;
	}
	free_2d(color);
}
