/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:03:49 by cramdani          #+#    #+#             */
/*   Updated: 2021/07/12 13:38:33 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	renders each frame
*/
int	render_frame(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img->img, 0, 0);
	return (1);
}
