/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:29:37 by quentin           #+#    #+#             */
/*   Updated: 2025/02/24 12:01:31 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_exit(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void error_prog(int argc, char *filename)
{
	int fd;

	if (argc != 2)
		error_exit("Invalid number of arguments. Usage: ./so_long <map.ber>");

	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4) != 0)
		error_exit("Unable to open the file. The file must have the .ber extension");

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Unable to open the file.");
	close(fd);
}

void error_map(char **map)
{
	int x;
	int y;
	int player_count;
	int exit_count;
	int collect_count;

	player_count = 0;
	exit_count = 0;
	collect_count = 0;

	if (!map)
		error_exit("Invalid card.");

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player_count++;
			else if (map[y][x] == 'E')
				exit_count++;
			else if (map[y][x] == 'C')
				collect_count++;
			else if (map[y][x] != '1' && map[y][x] != '0')
				error_exit("Invalid character in the map.");
			x++;
		}
		y++;
	}

	if (player_count != 1)
		error_exit("There must be exactly one player on the map.");
	if (exit_count != 1)
		error_exit("There must be exactly one exit on the map.");
	if (collect_count < 1)
		error_exit("There must be at least one collectible.");
}
void check_walls(char **map)
{
    int x; 
	int y;
    int width = ft_strlen(map[0]);
    int height = 0;
		
	x = 0;
	y = 0;
    while (map[height])
        height++;

    while(x < width)
    {
        if (map[0][x] != '1' || map[height - 1][x] != '1')
            error_exit("The map is not surrounded by walls.");
		x++;
    }

    while(y < height)
    {
        if (map[y][0] != '1' || map[y][width - 1] != '1')
            error_exit("The map is not surrounded by walls.");
		y++;
    }
	if(width == height)
		error_exit("The map is not rectangular.");
}

