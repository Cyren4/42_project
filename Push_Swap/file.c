/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:30:48 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/18 20:57:08 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

t_file	*initFile(char c)
{
	t_file	*f;

	f = malloc(sizeof(t_file));
	if (f == NULL)
		return (NULL);
	f->name = c;
	f->nbElt = 0;
	f->head = NULL;
	f->tail = NULL;
	return (f);
}

int	emptyFile(t_file *f)
{
	return (f == NULL || f->head == NULL);
}

t_file	*add(t_file *f, int val)
{
	t_eltFile	*new;

	new = malloc(sizeof(t_eltFile));
	if (new == NULL)
		return (NULL);
	new->val = val;
	new->next = NULL;
	if (emptyFile(f))
		f->head = new;
	else
		f->tail->next = new;
	f->tail = new;
	f->nbElt++;
	return (f);
}

int	clear_file(t_file *f)
{
	t_eltFile	*tmp;

	tmp = f->head;
	while (tmp != NULL)
	{
		f->head = f->head->next;
		free(tmp);
		tmp = f->head;
		f->nbElt--;
	}
	free(f);
	return (-1);
}
