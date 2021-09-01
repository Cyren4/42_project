/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:34:25 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/19 11:34:50 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order(t_file *f, int size, int (*test)(int, int))
{
	t_eltFile	*tmp;
	int			i;

	i = 0;
	tmp = f->head;
	if (emptyFile(f) || f->head == f->tail)
		return (1);
	while (tmp->next && i < size)
	{
		if (!test(tmp->val, tmp->next->val))
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	sort3(t_file *f)
{
	if (order(f, f->nbElt, &asc))
		return ;
	if (f->nbElt > 2)
	{
		if (f->head->val > f->head->next->val && f->head->val > f->tail->val)
			solo_op(f, &rotate);
		else if (f->head->next->val > f->head->val
			&& f->head->next->val > f->tail->val)
			solo_op(f, &rev_rotate);
	}
	if (f->nbElt >= 2 && f->head->val > f->head->next->val)
		solo_op(f, &swap);
}

void	emptyB(t_file *a, t_file *b)
{
	while (!emptyFile(b))
		push(b, a);
}

void	sort10(t_file *a, t_file *b)
{
	while (a->nbElt > 3 && !order(a, a->nbElt, &asc))
		findMin(a, b);
	sort3(a);
	emptyB(a, b);
}

int	*sort_tab(t_file *f, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		min(f, tab, i, size);
		i++;
	}
	return (tab);
}
