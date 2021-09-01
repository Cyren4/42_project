/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:18:03 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/18 20:58:16 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min(t_file *f, int *tab, int i, int size)
{
	t_eltFile	*tmp;
	int			min;
	int			count;

	count = 0;
	tmp = f->head;
	min = tab[i - 1];
	while (tmp && count < size)
	{
		if (min == tab[i - 1] && tmp->val > tab[i - 1])
			min = tmp->val;
		if (tmp->val < min)
			if (i == 0 || (tmp->val > tab[i - 1] && tmp->val < min))
				min = tmp->val;
		tmp = tmp->next;
		count++;
	}
	tab[i] = min;
}

int	allAbove(t_file *f, int ref)
{
	t_eltFile	*tmp;

	tmp = f->head;
	while (tmp)
	{
		if (tmp->val < ref)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	moveLess(t_file *a, t_file *b, int ref)
{
	int	(*op)(t_file *);

	while (!allAbove(a, ref))
	{
		if (a->head->val < ref)
			push(a, b);
		else if (a->tail->val < ref)
		{
			solo_op(a, &rev_rotate);
			push(a, b);
		}
		else
		{
			if (bestOp(a, ref))
				op = &rotate;
			else
				op = &rev_rotate;
			while (!(a->head->val < ref))
				solo_op(a, op);
			push(a, b);
		}
	}
}

int	bestOp(t_file *f, int ref)
{
	int			i;
	int			top;
	t_eltFile	*tmp;

	i = 0;
	top = -1;
	tmp = f->head;
	while (tmp && i == -1)
	{
		if (tmp->val < ref)
			top = i;
		tmp = tmp->next;
		i++;
	}
	if (top <= f->nbElt / 2)
		return (1);
	else
		return (0);
}

void	chunksort(t_file *a, t_file *b, int div)
{
	int	*tab;
	int	index;
	int	nbElt;

	nbElt = a->nbElt;
	index = nbElt / div;
	tab = sort_tab(a, a->nbElt);
	if (!tab)
	{
		clear_file(a);
		clear_file(b);
		exit(EXIT_FAILURE);
	}
	while (a->nbElt > 3)
	{
		moveLess(a, b, tab[index]);
		if (index + nbElt / div > nbElt)
			index = nbElt - 1;
		else
			index += nbElt / div;
	}
	sort3(a);
	while (!emptyFile(b))
		findMax(b, a);
	free(tab);
}
