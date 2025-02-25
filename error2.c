/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:46 by quentin           #+#    #+#             */
/*   Updated: 2025/02/25 15:18:28 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, char **visited)
{
	if (map[y][x] == '1' || map[y][x] == 'E' || visited[y][x] == '1')
		return ;
	visited[y][x] = '1';
	flood_fill(map, x + 1, y, visited);
	flood_fill(map, x - 1, y, visited);
	flood_fill(map, x, y + 1, visited);
	flood_fill(map, x, y - 1, visited);
}

char	**allocate_visited_map(char **map, int height)
{
	char	**visited;
	int		y;

	visited = malloc(sizeof(char *) * (height + 1));
	if (!visited)
		error_exit("Memory allocation error.");
	y = 0;
	while (y < height)
	{
		visited[y] = ft_strdup(map[y]);
		if (!visited[y])
			error_exit("Memory allocation error.");
		y++;
	}
	visited[height] = NULL;
	return (visited);
}

void	check_accessibility(char **map, int height, t_game *game)
{
	int		width;
	char	**visited;
	int		x;
	int		y;

	width = ft_strlen(map[0]);
	while (map[height])
		height++;
	visited = allocate_visited_map(map, height);
	find_player_position(game);
	if (game->player_x == -1 || game->player_y == -1)
		error_exit("Player (P) is not found on the map.");
	flood_fill(map, game->player_x, game->player_y, visited);
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			if ((map[y][x] == 'C' || map[y][x] == 'E') && visited[y][x] != '1')
				error_exit("Not all collectibles and the exit are accessible.");
	}
	y = -1;
	while (++y < height)
		free(visited[y]);
	free(visited);
}
