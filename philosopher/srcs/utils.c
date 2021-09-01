/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:09:34 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/10 11:37:51 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	nbr;

	nbr = 0;
	if (*str == '\0')
		return (-2);
	i = 0;
	while (str && str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-2);
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}

//	get current time
long long	get_time(void)
{
	struct timeval	stime;

	gettimeofday(&stime, NULL);
	return (stime.tv_sec * 1000 + stime.tv_usec / 1000);
}

//	get time difference in µs
long long	time_diff(long long start, long long end)
{
	return (end - start);
}

/*
	more precise than usleep
	and stops if someone died
*/
void	my_usleep(long long time_ms, t_table *tab)
{
	long long	start_time;
	int			state;

	start_time = get_time();
	while ((get_time() - start_time) < time_ms)
	{
		usleep(100);
		pthread_mutex_lock(&tab->write);
		state = tab->can_write;
		pthread_mutex_unlock(&tab->write);
		if (state == NO)
			return ;
	}
}
