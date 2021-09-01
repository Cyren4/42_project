/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:36:17 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/09 16:22:57 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ph_eat(t_philo *ph)
{
	if (ph->id % 2 == 1)
	{
		pthread_mutex_lock(ph->r_f);
		pthread_mutex_lock(ph->l_f);
	}
	else
	{
		pthread_mutex_lock(ph->l_f);
		pthread_mutex_lock(ph->r_f);
	}
	safe_print("has taken a fork", ph);
	safe_print("has taken a fork", ph);
	safe_print("is eating", ph);
	pthread_mutex_lock(&ph->tab->m_eat);
	ph->t_since_eat = get_time();
	pthread_mutex_unlock(&ph->tab->m_eat);
	my_usleep(ph->tab->t_eat, ph->tab);
	pthread_mutex_lock(&ph->tab->m_eat);
	ph->nb_meal++;
	if (ph->nb_meal == ph->tab->nb_eat_tour)
		ph->tab->finish_eat++;
	pthread_mutex_unlock(&ph->tab->m_eat);
	pthread_mutex_unlock(ph->l_f);
	pthread_mutex_unlock(ph->r_f);
	return (0);
}

int	routine(t_philo *ph)
{
	int	state;

	pthread_mutex_lock(&ph->tab->write);
	state = ph->tab->can_write;
	pthread_mutex_unlock(&ph->tab->write);
	if (state == NO)
		return (0);
	ph_eat(ph);
	safe_print("is sleeping", ph);
	my_usleep(ph->tab->t_sleep, ph->tab);
	safe_print("is thinking", ph);
	pthread_mutex_lock(&ph->tab->write);
	state = ph->tab->can_write;
	pthread_mutex_unlock(&ph->tab->write);
	if (state == YES)
		routine(ph);
	return (0);
}

void	*ft_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->id % 2 == 0)
		usleep(100);
	routine((t_philo *)philo);
	return (NULL);
}
