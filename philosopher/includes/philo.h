/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:02:04 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/09 14:47:17 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define YES 1
# define NO 0

struct	s_table;
typedef struct s_philo
{
	int				id;
	pthread_t		th;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	*l_f;
	long long		t_since_eat;
	long long		nb_meal;
	struct s_table	*tab;
}	t_philo;

typedef struct s_table
{
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	write;
	pthread_mutex_t	m_die;
	pthread_mutex_t	m_eat;
	long long		start;
	int				can_write;
	long long		nb_philo;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	long long		nb_eat_tour;
	int				finish_eat;
}	t_table;

/*  utils.c		*/
long long	ft_atoi(const char *str);
long long	get_time(void);
long long	time_diff(long long start, long long end);
void		my_usleep(long long time_ms, t_table *tab);

/*	print.c	*/
void		safe_print(char *str, t_philo *ph);
void		p_fork(t_philo *ph);
int			p_die(t_philo *ph);

/*  start.c		*/
int			start(t_table *tab);
int			init_fork(t_table *tab);
int			check_death(t_table *tab);

/*	alone.c	*/
void		alone(t_table *tab);

/*	routine.c	*/
int			routine(t_philo *ph);
void		*ft_routine(void *philo);

/*  finish.c	*/
int			clear_mut(t_table *tab, int max);
int			clear_th(t_table *tab);
int			finish_meal(t_table *tab);

#endif