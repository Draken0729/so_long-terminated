/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:32:03 by quentin           #+#    #+#             */
/*   Updated: 2025/02/25 13:35:09 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Unable to open the map file.");
	temp = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\n')
			error_exit("Error: The map contains a blank line.");
		temp = ft_strjoin(temp, line);
		game->map_width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!temp)
		error_exit("Error: empty map.");
	return (process_map(temp, game));
}

char	**process_map(char *map_data, t_game *game)
{
	char	**map;
	int		count_height;

	count_height = 0;
	map = ft_split(map_data, '\n');
	while (map[count_height])
		count_height++;
	game->map_height = count_height;
	free(map_data);
	return (map);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->textures.wall = mlx_xpm_file_to_image(game->mlx, "sprites/stone.xpm",
			&width, &height);
	if (!game->textures.wall)
		error_exit("Error loading wall.");
	game->textures.floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm",
			&width, &height);
	if (!game->textures.floor)
		error_exit("Error loading floor.");
	game->textures.player = mlx_xpm_file_to_image(game->mlx, "sprites/fox.xpm",
			&width, &height);
	if (!game->textures.player)
		error_exit("Error loading player.");
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"sprites/chicken.xpm", &width, &height);
	if (!game->textures.collectible)
		error_exit("Error loading collectible.");
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
			&width, &height);
	if (!game->textures.exit)
		error_exit("Error loading exit.");
}

void	render_map_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * TS,
		y * TS);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x
			* TS, y * TS);
	else if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x
			* TS, y * TS);
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x
			* TS, y * TS);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, x * TS, y * TS);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			render_map_tile(game, x, y);
	}
}
