/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:03:49 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/12 19:06:39 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	prints nbMove in the window
*/
void	movement(t_game *g)
{
	char	*s;

	s = ft_itoa(g->nbMove);
	mlx_string_put(g->mlx, g->win, 20, 20, 0x00fff, s);
	free(s);
}

int	which_text(char c)
{
	if (c == '1')
		return (NWALL);
	else if (c == 'E')
		return (NEXIT);
	else if (c == 'C')
		return (NCOL);
	return (NSPACE);
}

/*
	returns a pixel color	
*/
unsigned int	get_col(t_data *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bits_pixel / 8));
	return (*(unsigned int *)dst);
}

/*
	renders each frame
*/
int	render_frame(t_game *g)
{
	static int	anim = 0;
	static int	prob = 0;
	char		*s;

	if (g->map->patrol[0] == g->map->player[0]
		&& g->map->patrol[1] == g->map->player[1])
		close_g(g);
	s = ft_itoa(g->nbMove);
	my_mlx_pixel_put(g->img, g->map->patrol[0] * IMG_SIZE,
		g->map->patrol[1] * IMG_SIZE, &g->text[NPATROL]);
	my_mlx_pixel_put(g->img, g->map->player[0] * IMG_SIZE,
		g->map->player[1] * IMG_SIZE, &g->text[NPLAY1 + anim]);
	mlx_put_image_to_window(g->mlx, g->win, g->img->img, 0, 0);
	mlx_string_put(g->mlx, g->win, g->map->player[0] * IMG_SIZE,
		g->map->player[1] * IMG_SIZE, RED, s);
	free(s);
	prob++;
	if (prob == PROB)
	{
		prob = 0;
		anim++;
		if (anim == 3)
			anim = 0;
	}
	return (1);
}
