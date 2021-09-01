/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:57:50 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/10 22:59:25 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	checks if the line is valid
	-> not empty / invalid char
*/
int	check_line(char *line, int *val)
{
	int	i;

	i = 0;
	if (!line || ft_strcmp(line, "") == 0)
		*val = 0;
	while (line[i])
	{
		if (!valid_char(line[i]))
			*val = 0;
		i++;
	}
	return (1);
}

/*
	gets player position
	counts number of collectibles and exits
*/
static void	majMap(char c, t_map *map, int x, int y)
{
	if (c == 'P')
	{
		map->start += 1;
		map->player[0] = x;
		map->player[1] = y;
	}
	else if (c == 'C')
		map->col += 1;
	else if (c == 'E')
		map->exit += 1;
}

/*
	checks the map requirements :
		-	1 starting point
		-	at least 1 exit
		-	at least 1 collectible
		-	wall surrounding the map
		-	rectangular map	
	prints error message otherwise
	return 1 if valid, 0 otherwise
*/
int	check_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		if (map->x != -1 && (int)ft_strlen(map->map[y]) != map->x)
			return (error_map(map, "Map not rectangular\n"));
		while (map->map[y][x] != '\0')
		{
			if (need_wall(map, y, x) && map->map[y][x] != '1')
				return (error_map(map, "Map not closed\n"));
			else if (map->map[y][x] == 'P' || map->map[y][x] == 'C'
				|| map->map[y][x] == 'E')
				majMap(map->map[y][x], map, x, y);
			x++;
		}
		if (map->map[y][x] == '\0' && map->x == -1)
			map->x = x;
		y++;
	}
	map->y = y;
	return (enough(map));
}

/*
	joins 2 lines with the separator '\t' in between
*/
char	*joinT(char *s1, char *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\t';
	i++;
	while (s2 && s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	free(s1);
	return (str);
}

/*
	reads the file and joins it with '\t' separator
	calls check_line
	splits it with '\t' separator to get the map
	returns 1 if all requirements are respected, 0 otherwise
*/
int	get_map(int fd, t_map *map)
{
	char	*str;
	char	*line;
	int		ret;
	int		valLine;

	ret = 1;
	str = NULL;
	valLine = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1 || !check_line(line, &valLine))
			error_read(fd, str, line, map);
		str = joinT(str, line);
		free(line);
	}
	close(fd);
	map->map = ft_split(str, '\t');
	free(str);
	if (map->map == NULL)
		return (error_split(map));
	if (valLine == 0)
		return (error_map(map, "Invalid line\n"));
	return (check_map(map));
}
