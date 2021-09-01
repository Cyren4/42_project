/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:35:48 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/18 20:57:32 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return 1 si int valide 0 sinon
int	valid_int(char *str)
{
	int			i;
	long int	nbr;
	int			neg;

	if (ft_strlen(str) > 10 || (ft_strlen(str) == 1 && str[0] == '-'))
		return (0);
	i = 0;
	nbr = 0;
	neg = str[i] == '-';
	if (neg)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (neg)
		return (-nbr >= INT_MIN);
	else
		return (nbr <= INT_MAX);
}

// return 1 si nb n'est pas deja dans la stack 0 sinon
int	not_in_file(t_file *f, int nb)
{
	t_eltFile	*tmp;

	if (emptyFile(f))
		return (1);
	tmp = f->head;
	while (tmp)
	{
		if (tmp->val == nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_args(t_file *f, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (av[i])
		{
			if (valid_int(av[i]) && not_in_file(f, ft_atoi(av[i])))
			{
				if (add(f, ft_atoi(av[i])) == NULL)
				{
					clear_file(f);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				ft_putendl_fd("Error\n", 2);
				clear_file(f);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	return (1);
}
