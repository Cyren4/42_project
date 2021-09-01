/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:03:49 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/11 17:35:21 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	draws textures at (x,y)	in img
*/
void	my_mlx_pixel_put(t_data *img, int x, int y, t_data *text)
{
	char	*dst;
	int		xm;
	int		ym;

	text->addr = mlx_get_data_addr(text->img, &text->bits_pixel,
			&text->line_l, &text->endian);
	ym = y;
	while (ym < y + IMG_SIZE)
	{
		xm = x;
		while (xm < x + IMG_SIZE)
		{
			dst = img->addr + (ym * img->line_l + xm * (img->bits_pixel / 8));
			*(unsigned int *)dst = get_col(text, xm - x, ym - y);
			xm++;
		}
		ym++;
	}
}

/*
	goes through the map and calls my_mlx_pixel_put 
*/
void	textMap(t_game *g, t_data *img)
{
	int	xm;
	int	ym;
	int	text;

	xm = 0;
	ym = 0;
	while (g->map->map[ym] != NULL)
	{
		xm = 0;
		while (g->map->map[ym][xm] != '\0')
		{
			text = which_text(g->map->map[ym][xm]);
			if (g->map->player[0] == xm && g->map->player[1] == ym)
				text = NPLAY1;
			my_mlx_pixel_put(img, xm * IMG_SIZE, ym * IMG_SIZE, &g->text[text]);
			xm++;
		}
		ym++;
	}
}

/*
	game loop
	dispatch to handlers render_frame and key_hook 
*/
void	play_game(t_game *g)
{
	mlx_loop_hook(g->mlx, render_frame, g);
	mlx_key_hook(g->win, key_hook, g);
	mlx_hook(g->win, 17, (1L << 17), close_g, g);
	mlx_loop(g->mlx);
}

/*
	calls init_game
	creates image and gets it's adress
	calls textMap 
	calls play_game
*/
void	start_game(t_map *map)
{
	t_game	*g;
	t_data	img;

	g = init_game(map);
	img.img = mlx_new_image(g->mlx, map->x * IMG_SIZE, map->y * IMG_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pixel, &img.line_l,
			&img.endian);
	textMap(g, &img);
	g->img = &img;
	play_game(g);
}
