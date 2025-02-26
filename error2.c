/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:46 by quentin           #+#    #+#             */
/*   Updated: 2025/02/26 11:01:51 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **visited, int x, int y)
{
	if (x < 0 || y < 0 || !visited[y] || x >= (int)ft_strlen(visited[y]))
		return ;
	if (visited[y][x] == '1' || visited[y][x] == 'V')
		return ;
	visited[y][x] = 'V';
	flood_fill(visited, x + 1, y);
	flood_fill(visited, x - 1, y);
	flood_fill(visited, x, y + 1);
	flood_fill(visited, x, y - 1);
}

char	**allocate_visited_map(char **map, int height)
{
	char	**visited;
	int		y;

	visited = malloc(sizeof(char *) * (height + 1));
	if (!visited)
		error_exit_map("Memory allocation error.", map);
	y = 0;
	while (y < height)
	{
		visited[y] = ft_strdup(map[y]);
		if (!visited[y])
			error_exit_map("Memory allocation error.", map);
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
		error_exit_map("Player (P) is not found on the map.", map);
	flood_fill(visited, game->player_x, game->player_y);
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			if ((map[y][x] == 'C' || map[y][x] == 'E') && visited[y][x] != 'V')
				error_exit_map("Not all collectibles and the exit are accessible.", map);
	}
	y = -1;
	while (++y < height)
		free(visited[y]);
	free(visited);
}
void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

