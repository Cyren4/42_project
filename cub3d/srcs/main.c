/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 11:55:25 by cramdani          #+#    #+#             */
/*   Updated: 2021/08/26 21:32:27 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int usage(char *mes)
{
	printf("Error\n");
	if (mes)
		printf("%s\n", mes);
	printf("Usage : ./cub3d.a file.cub [--save]\n");
	return (-1);
}

//check the arguments : 
//arg1 : *.cub              --> return 1
//arg2 (optionnal) : --save --> return 2
// return 0 if error
int	check_name_file(int ac, char **av)
{
	if (ac < 2)
		usage("Not enough arguments");
	else if (ac > 3)
		usage("Too many arguments");
	else if (strcmp((av[1] + strlen(av[1]) - 4), ".cub") != 0)
		usage("This program can't take other file than *.cub");
	else
	{
		if (ac != 3)
			return (1);
		if (strcmp(av[2], "--save") != 0)
			usage("Second argument invalid");
		else 
			return (2);
}
    return (0);
}

int		main(int ac, char **av)
{
	int		check;
	t_data	data;
	int		fd;

	if ((check = check_name_file(ac, av)) > 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			perror("Error");
		else if (check_cub(av[1], &data) == 1)
			printf("%s\n", check == 2 ? "screen" : "play"); //start(data)
		else
            printf("%s file invalid\n", av[1]);
	} else
		return (-1);
//	system("leaks a.out");
	return (0);
}
