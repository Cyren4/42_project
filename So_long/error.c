/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:48:49 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/11 17:01:12 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_malloc(char *message)
{
	write(STDERR_FILENO, "Error\n", 7);
	write(STDERR_FILENO, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	error_read(int fd, char *str, char *line, t_map *map)
{
	write(STDERR_FILENO, "Error\nCouldn't read file\n", 26);
	if (str)
		free(str);
	if (line)
		free(line);
	free(map);
	close(fd);
	exit(EXIT_FAILURE);
}

int	error_split(t_map *map)
{
	write(STDERR_FILENO, "Error\nCouldn't get the map\n", 28);
	free(map);
	perror("");
	exit(EXIT_FAILURE);
	return (0);
}

int	error_map(t_map *map, char *message)
{
	write(STDERR_FILENO, "Error\n", 7);
	write(STDERR_FILENO, message, ft_strlen(message));
	clear_map(map);
	exit(EXIT_FAILURE);
	return (0);
}
