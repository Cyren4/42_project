/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:56:31 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/09 16:28:40 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_no(t_table *tab)
{
	pthread_mutex_lock(&tab->write);
	tab->can_write = NO;
	pthread_mutex_unlock(&tab->write);
}

/*
	checks if every philo ate enough
	and if anyone died
*/
int	check_death(t_table *tab)
{
	int			i;
	long long	t_eat;

	i = 0;
	pthread_mutex_lock(&tab->m_eat);
	if (tab->finish_eat >= tab->nb_philo)
		return (finish_meal(tab));
	pthread_mutex_unlock(&tab->m_eat);
	pthread_mutex_lock(&tab->m_die);
	while (i < tab->nb_philo)
	{
		pthread_mutex_lock(&tab->m_eat);
		t_eat = tab->philo[i].t_since_eat;
		pthread_mutex_unlock(&tab->m_eat);
		if (time_diff(t_eat, get_time()) > tab->t_die)
		{
			safe_print("died", &tab->philo[i]);
			set_no(tab);
			pthread_mutex_unlock(&tab->m_die);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&tab->m_die);
	return (1);
}

/*
	inits forks and philosophers' id
	if an error occur it destroys every mutex created earlier
*/
int	init_fork(t_table *tab)
{
	int	i;

	i = 0;
	while (i < tab->nb_philo)
	{
		if (pthread_mutex_init(&tab->forks[i], NULL))
			return (clear_mut(tab, i));
		tab->philo[i].id = i + 1;
		tab->philo[i].nb_meal = 0;
		tab->philo[i].t_since_eat = get_time();
		tab->philo[i].tab = tab;
		tab->philo[i].r_f = &tab->forks[i];
		if (i == tab->nb_philo - 1)
			tab->philo[0].l_f = &tab->forks[i];
		if (i != 0)
			tab->philo[i].l_f = &tab->forks[i - 1];
		i++;
	}
	return (1);
}

/*
	inits monitoring mutex (write / death)
	inits forks and philosophers
	starts odd and then even philosophers 100µs after
*/
int	start(t_table *tab)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&tab->write, NULL)
		|| pthread_mutex_init(&tab->m_die, NULL)
		|| pthread_mutex_init(&tab->m_eat, NULL))
		return (0);
	tab->finish_eat = 0;
	tab->can_write = YES;
	if (!init_fork(tab))
		return (0);
	while (i < tab->nb_philo)
	{
		if (pthread_create(&tab->philo[i].th, NULL, ft_routine, &tab->philo[i]))
			return (clear_th(tab));
		i++;
	}
	while (check_death(tab))
		usleep(10);
	return (clear_th(tab));
}
