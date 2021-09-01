/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:52:37 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/10 23:19:56 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	need_wall(t_map	*map, int y, int x)
{
	return (y == 0 || map->map[y + 1] == NULL || x == 0
		|| map->map[y][x + 1] == '\0');
}

/*
	checks map requirements and calls error_map
*/
int	enough(t_map *map)
{
	if (map->start < 1)
		return (error_map(map, "No starting point\n"));
	else if (map->start > 1)
		return (error_map(map, "Too many starting point\n"));
	else if (map->exit < 1)
		return (error_map(map, "No exit\n"));
	else if (map->col < 1)
		return (error_map(map, "No collectible\n"));
	return (1);
}

/*
	clears t_map 
*/
void	clear_map(t_map *map)
{
	int	y;

	y = 0;
	while (map && map->map && map->map[y] != NULL)
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
	free(map);
}
