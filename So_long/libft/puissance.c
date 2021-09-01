/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:56:48 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/17 16:38:55 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	puissance(int nb, int puis)
{
	int	res;

	res = 1;
	while (puis > 0)
	{
		res *= nb;
		puis--;
	}
	return (res);
}
