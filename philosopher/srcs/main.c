/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 01:04:54 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/10 11:35:33 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	usage(char *mess)
{
	printf("Error\n%s\n", mess);
	printf("Usage : ./philo number_of_philosophers time_to_die time_to_eat \
	time_to_sleep [number_of_times_each_philosopher_must_eat]");
	return (-1);
}

int	unvalid(t_table tab)
{
	if (tab.nb_philo <= 0)
		usage("Invalid arguments (1) : number_of_philosophers");
	else if (tab.nb_philo > 200)
		usage("Invalid arguments (1) : (too many) number_of_philosophers");
	else if (tab.t_die < 0)
		usage("Invalid arguments (2) : time_to_die");
	else if (tab.t_eat < 0)
		usage("Invalid arguments (3) : time_to_eat");
	else if (tab.t_sleep < 0)
		usage("Invalid arguments (4) : time_to_sleep");
	else if (tab.nb_eat_tour < -1)
		usage("Invalid arguments (5) : [nb_times_each_philosopher_must_eat]");
	else
		return (0);
	return (1);
}

void	check_args(char **av, int nbArg)
{
	t_table	tab;

	tab.nb_philo = ft_atoi(av[0]);
	tab.t_die = ft_atoi(av[1]);
	tab.t_eat = ft_atoi(av[2]);
	tab.t_sleep = ft_atoi(av[3]);
	if (nbArg == 5)
		tab.nb_eat_tour = ft_atoi(av[4]);
	else
		tab.nb_eat_tour = -1;
	tab.start = get_time();
	if (!unvalid(tab))
	{
		if (tab.nb_eat_tour == 0)
			printf("Each philosopher ate 0 time(s)\n");
		else if (tab.nb_philo == 1)
			alone(&tab);
		else
			start(&tab);
	}
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
		check_args(av + 1, ac - 1);
	else
		return (usage("Invalid number of arguments"));
	return (0);
}
