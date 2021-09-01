/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:57:14 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/09 14:52:34 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	print only if no philosopher died
*/
void	safe_print(char *str, t_philo *ph)
{
	long long	time;

	pthread_mutex_lock(&ph->tab->write);
	time = time_diff(ph->tab->start, get_time());
	if (ph->tab->can_write == YES)
		printf("%lld Philo %d %s\n", time, ph->id, str);
	pthread_mutex_unlock(&ph->tab->write);
}

/*	checks if every philosophers ate the required nb */
int	finish_meal(t_table *tab)
{
	pthread_mutex_lock(&tab->write);
	if (tab->can_write == YES && tab->finish_eat == tab->nb_philo)
		printf("Each philosopher ate %lld time(s)\n", tab->nb_eat_tour);
	tab->can_write = NO;
	pthread_mutex_unlock(&tab->write);
	tab->finish_eat++;
	pthread_mutex_unlock(&tab->m_eat);
	return (0);
}

int	p_die(t_philo *ph)
{
	pthread_mutex_lock(&ph->tab->m_die);
	pthread_mutex_unlock(&ph->tab->m_die);
	pthread_mutex_lock(&ph->tab->write);
	printf("%lld Philo %d died\n",
		time_diff(ph->tab->start, get_time()), ph->id);
	pthread_mutex_unlock(&ph->tab->write);
	return (1);
}
