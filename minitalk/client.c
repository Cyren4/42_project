#include "minitalk.h"

int	check_args(int ac, char **av, pid_t *pid)
{
	int	ret;

	if ((ac == 2 || ac == 3) && ft_strlen(av[1]) < 11)
	{
		ret = ft_atoi(av[1]);
		if (ret == -1)
			return (0);
		*pid = ret;
	}
	else
		return (0);
	return (1);
}

void	handler(int sig)
{
	(void)sig;
}

void	success(void)
{
	struct sigaction	s;

	s.sa_handler = &handler;
	sigaction(SIGUSR1, &s, NULL);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	success();
	if (!check_args(ac, av, &pid))
	{
		write(1, "Usage: ./client <server_PID> <message>\n", 40);
		exit(EXIT_FAILURE);
	}
	if (ac == 3)
		send_message(pid, av[2]);
	return (0);
}
