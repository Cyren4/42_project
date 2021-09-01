/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:30:17 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/12 18:35:28 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	inits textures from xpm files
*/
t_data	*init_text(t_game *g)
{
	int		gab[2];
	t_data	*text;

	text = malloc(sizeof(t_data) * 9);
	text[0].img = mlx_xpm_file_to_image(g->mlx, COL, &gab[0], &gab[1]);
	text[1].img = mlx_xpm_file_to_image(g->mlx, EXI, &gab[0], &gab[1]);
	text[2].img = mlx_xpm_file_to_image(g->mlx, SPAC, &gab[0], &gab[1]);
	text[3].img = mlx_xpm_file_to_image(g->mlx, WALL, &gab[0], &gab[1]);
	text[4].img = mlx_xpm_file_to_image(g->mlx, PLAY1, &gab[0], &gab[1]);
	text[5].img = mlx_xpm_file_to_image(g->mlx, PLAY2, &gab[0], &gab[1]);
	text[6].img = mlx_xpm_file_to_image(g->mlx, PLAY3, &gab[0], &gab[1]);
	text[7].img = mlx_xpm_file_to_image(g->mlx, PLAY4, &gab[0], &gab[1]);
	text[8].img = mlx_xpm_file_to_image(g->mlx, PATROL, &gab[0], &gab[1]);
	return (text);
}

/*
	inits t_game structure with window and mlx_ptr
	calls init_text 
*/
t_game	*init_game( t_map *map)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	g->map = map;
	g->nbMove = 0;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, map->x * IMG_SIZE, map->y * IMG_SIZE,
			"So_long");
	g->text = init_text(g);
	return (g);
}

/*
	clear t_game structure
*/
void	clear_g(t_game *g)
{
	free(g->mlx);
	clear_map(g->map);
	free(g->text);
	free(g);
}

/*
	closes the game properly
	calls clear_g
*/
int	close_g(t_game *g)
{
	int	i;

	i = 0;
	write(1, "Game Over\n", 10);
	if (g->map->col == 0
		&& g->map->map[g->map->player[1]][g->map->player[0]] == 'E')
		write(1, "You won!\n", 9);
	else
		write(1, "You lost!\n", 10);
	if (g->mlx)
	{
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		while (i < 9)
		{
			mlx_destroy_image(g->mlx, g->text[i].img);
			i++;
		}
		mlx_destroy_image(g->mlx, g->img->img);
		mlx_destroy_display(g->mlx);
	}
	clear_g(g);
	exit(EXIT_SUCCESS);
	return (0);
}
