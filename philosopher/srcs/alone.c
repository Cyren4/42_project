/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:34:09 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/09 14:30:54 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_alone(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	ph->tab->start = get_time();
	safe_print("has taken a fork", ph);
	while (time_diff(ph->tab->start, get_time()) < ph->tab->t_die)
		usleep(100);
	printf("%lld Philo %d died\n",
		time_diff(ph->tab->start, get_time()), ph->id);
	return (NULL);
}

void	alone(t_table *tab)
{
	if (pthread_mutex_init(&tab->forks[0], NULL))
		return ;
	tab->philo[0].id = 1;
	tab->philo[0].tab = tab;
	tab->philo[0].r_f = &tab->forks[0];
	tab->can_write = YES;
	if (pthread_create(&tab->philo[0].th, NULL, ft_alone, &tab->philo[0]))
	{
		pthread_mutex_destroy(&tab->forks[0]);
		return ;
	}
	pthread_mutex_destroy(&tab->forks[0]);
	pthread_join(tab->philo[0].th, NULL);
}
