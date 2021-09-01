/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:47:21 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/17 16:17:20 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "file.h"
# include <limits.h>

/* check_args.h */
int		check_args(t_file *f, int ac, char **av);
int		not_in_file(t_file *f, int nb);
int		valid_int(char *str);

/* utils.c */
int		asc(int cur, int next);
int		desc(int cur, int next);
void	findMin(t_file *a, t_file *b);
void	findMax(t_file *a, t_file *b);
int		bestOp(t_file *f, int ref);

/* sort.c */
int		order(t_file *f, int size, int (*test)(int, int));
void	sort3(t_file *a);
void	sort10(t_file *a, t_file *b);
void	emptyB(t_file *a, t_file *b);
int		*sort_tab(t_file *f, int size);

/* quicksort.c */
void	min(t_file *f, int *tab, int i, int size);
int		allAbove(t_file *f, int ref);
void	moveLess(t_file *a, t_file *b, int ref);
int		bestOp(t_file *f, int ref);
void	chunksort(t_file *a, t_file *b, int div);

#endif