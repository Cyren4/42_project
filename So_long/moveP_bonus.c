/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveP_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:11:52 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/12 19:01:50 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	whereMove(t_game *g, int *x, int *y)
{
	int	xp;
	int	yp;

	*x = 0;
	*y = 0;
	xp = g->map->patrol[0];
	yp = g->map->patrol[1];
	if (g->map->player[0] > xp && g->map->map[yp][xp + 1] != '1')
		*x = 1;
	else if (g->map->player[0] < xp && g->map->map[yp][xp - 1] != '1')
		*x = -1;
	else if (g->map->player[1] > yp && g->map->map[yp + 1][xp] != '1')
		*y = 1;
	else if (g->map->player[1] < xp && g->map->map[yp - 1][xp] != '1')
		*y = -1;
}

void	majPatrol(t_game *g, t_data *img)
{
	int	xp;
	int	yp;
	int	x;
	int	y;

	xp = g->map->patrol[0];
	yp = g->map->patrol[1];
	whereMove(g, &x, &y);
	if (g->map->map[yp + y][xp + x] != '1')
	{
		my_mlx_pixel_put(img, g->map->patrol[0] * IMG_SIZE, g->map->patrol[1]
			* IMG_SIZE, &g->text[which_text(g->map->map[yp][xp])]);
		g->map->patrol[0] += x;
		g->map->patrol[1] += y;
		my_mlx_pixel_put(img, g->map->patrol[0] * IMG_SIZE, g->map->patrol[1]
			* IMG_SIZE, &g->text[NPATROL]);
	}
}

/*
	draws player after deplacement
*/
void	majPlayer(t_game *g, int x, int y, t_data *img)
{
	int	xp;
	int	yp;

	majPatrol(g, img);
	xp = g->map->player[0];
	yp = g->map->player[1];
	if (g->map->map[yp + y][xp + x] != '1')
	{
		my_mlx_pixel_put(img, g->map->player[0] * IMG_SIZE, g->map->player[1]
			* IMG_SIZE, &g->text[which_text(g->map->map[yp][xp])]);
		if (g->map->map[yp + y][xp + x] == 'C')
		{
			g->map->map[yp + y][xp + x] = '0';
			g->map->col--;
		}
		g->map->player[0] += x;
		g->map->player[1] += y;
		g->nbMove++;
		my_mlx_pixel_put(img, g->map->player[0] * IMG_SIZE, g->map->player[1]
			* IMG_SIZE, &g->text[NPLAY1]);
		if (g->map->col == 0 && g->map->map[yp + y][xp + x] == 'E')
			close_g(g);
	}
	ft_printf("%d\n", g->nbMove);
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == KEY_A)
		majPlayer(g, -1, 0, g->img);
	else if (keycode == KEY_W)
		majPlayer(g, 0, -1, g->img);
	else if (keycode == KEY_D)
		majPlayer(g, 1, 0, g->img);
	else if (keycode == KEY_S)
		majPlayer(g, 0, 1, g->img);
	else if (keycode == KEY_ESC)
		close_g(g);
	return (keycode);
}
