/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:28:30 by htam              #+#    #+#             */
/*   Updated: 2023/06/26 10:41:02 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_extension(char *file)
{
	int	offset;

	offset = ft_strlen(file) - 4;
	if (offset <= 0)
	{
		ft_printf("Error\nInvalid extension\n");
		return (-1);
	}
	if (ft_strcmp(file + offset, ".cub"))
	{
		ft_printf("Error\nInvalid extension\n");
		return (-1);
	}
	return (0);
}

int	check_file(char *file)
{
	int	cub_fd;

	if (check_extension(file) == -1)
		return (-1);
	cub_fd = open(file, O_RDONLY);
	if (cub_fd == -1)
	{
		ft_printf("Error\nCannot open: %s\n", file);
		return (-1);
	}
	return (cub_fd);
}

void	init_cub(t_cub *cub)
{
	int	n;

	n = 0;
	cub->north_file = NULL;
	cub->east_file = NULL;
	cub->south_file = NULL;
	cub->west_file = NULL;
	cub->map = NULL;
	while (n < 3)
	{
		cub->floor[n] = -1;
		cub->ceiling[n] = -1;
		n++;
	}
}

int	map_1d_check(char *map_1d)
{
	int	n;
	int	player_count;

	n = 0;
	player_count = 0;
	while (*map_1d == '\n')
		map_1d++;
	while (map_1d[n])
	{
		if (is_player(map_1d[n]))
			player_count++;
		if (map_1d[n] != '1' && map_1d[n] != '0' && !is_player(map_1d[n])
			&& map_1d[n] != '\n' && map_1d[n] != ' ')
			return (-1);
		if (map_1d[n] == '\n' && map_1d[n + 1] && map_1d[n + 1] == '\n')
			return (-1);
		n++;
	}
	if (player_count != 1)
		return (-1);
	return (0);
}

t_cub	*cub_parse(char *file)
{
	t_cub	*cub;
	int		cub_fd;
	int		check;

	cub_fd = check_file(file);
	if (cub_fd == -1)
		return (NULL);
	cub = malloc(sizeof(*cub));
	if (!cub)
		return (NULL);
	init_cub(cub);
	check = read_cub_file(cub_fd, cub);
	close(cub_fd);
	if (check < 0)
		return (free_cub(cub), NULL);
	if (valid_cub(cub) == -1)
		return (free_cub(cub), NULL);
	return (cub);
}
