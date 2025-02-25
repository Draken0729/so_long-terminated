/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:29:37 by quentin           #+#    #+#             */
/*   Updated: 2025/02/25 14:09:16 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map_characters(char **map, int *player_count, int *exit_count,
		int *collect_count)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				(*player_count)++;
			else if (map[y][x] == 'E')
				(*exit_count)++;
			else if (map[y][x] == 'C')
				(*collect_count)++;
			else if (map[y][x] != '1' && map[y][x] != '0')
				error_exit("Invalid character in the map.");
			x++;
		}
		y++;
	}
}

void	error_map(char **map)
{
	int	player_count;
	int	exit_count;
	int	collect_count;

	player_count = 0;
	exit_count = 0;
	collect_count = 0;
	if (!map)
		error_exit("Invalid map.");
	validate_map_characters(map, &player_count, &exit_count, &collect_count);
	if (player_count != 1)
		error_exit("There must be exactly one player on the map.");
	if (exit_count != 1)
		error_exit("There must be exactly one exit on the map.");
	if (collect_count < 1)
		error_exit("There must be at least one collectible.");
}

void	check_walls(char **map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	width = ft_strlen(map[0]);
	height = 0;
	x = 0;
	y = 0;
	while (map[height])
		height++;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			error_exit("The map is not surrounded by walls.");
		x++;
	}
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			error_exit("The map is not surrounded by walls.");
		y++;
	}
	if (width == height)
		error_exit("The map is not rectangular.");
}
