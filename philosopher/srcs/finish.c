/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:46:02 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/06 21:08:05 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*	destroy mutex */
int	clear_mut(t_table *tab, int max)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&tab->write);
	pthread_mutex_destroy(&tab->m_die);
	pthread_mutex_destroy(&tab->m_eat);
	while (i < max)
	{
		pthread_mutex_destroy(&tab->forks[i]);
		i++;
	}
	return (0);
}

/*	destroy mutex and join threads
	&tab->philo[i].th
*/
int	clear_th(t_table *tab)
{
	int	i;

	i = 0;
	while (i < tab->nb_philo)
	{
		pthread_join(tab->philo[i].th, NULL);
		i++;
	}
	return (clear_mut(tab, tab->nb_philo));
}
