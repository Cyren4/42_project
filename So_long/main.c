/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:42:24 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/11 17:36:50 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	inits map structure 
*/
static void	init_map(t_map *map)
{
	map->map = NULL;
	map->x = -1;
	map->y = -1;
	map->start = 0;
	map->col = 0;
	map->exit = 0;
}

/*
	opens .ber file
	calls the map getter and checker
	return 1 if it's good or 0 otherwise
*/
int	check_arg(char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < -1)
	{
		ft_printf("Error\nCouldn't open %s\n", file);
		perror("");
		close(fd);
		free(map);
		exit(EXIT_FAILURE);
	}
	return (get_map(fd, map));
}

/*
	checks arguments and print the usage
	calls init_map 
	calls the file checker
	if everything is respected it starts the game
*/
int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2 || ft_strlen(av[1]) < 5
		|| ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".ber"))
		write(STDERR_FILENO, "Error\nUsage: ./so_long [file.ber]\n", 35);
	else
	{
		map = malloc(sizeof(t_map));
		if (!map)
			error_malloc("Map malloc error.");
		init_map(map);
		if (check_arg(av[1], map))
			start_game(map);
	}
	return (0);
}
