/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:59:28 by qbaret            #+#    #+#             */
/*   Updated: 2025/02/25 13:27:17 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	error_prog(int argc, char *filename)
{
	int	fd;

	if (argc != 2)
		error_exit("Invalid number of arguments. Usage: ./so_long <map.ber>");
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4) != 0)
		error_exit("Unable to open the file.Need the .ber extension");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Unable to open the file.");
	close(fd);
}

void	check_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error initializing MLX.");
	game->win = mlx_new_window(game->mlx, game->map_width * TS, game->map_height
			* TS, "so_long");
	if (!game->win)
		error_exit("Error creating the window.");
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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
