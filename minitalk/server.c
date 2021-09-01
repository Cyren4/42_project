#include "minitalk.h"

static pid_t	g_current = -1;

void	print(char c)
{
	static char	buf[1025] = {0};
	static int	i = 0;

	if (i == 1024 || c == '\0')
	{
		if (i == 1024 && c != '\0')
		{
			buf[i] = c;
			write(1, buf, i + 1);
		}
		else if (c == '\0')
			write(1, buf, i);
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		*buf = 0;
		i = 0;
	}
	else
	{
		buf[i] = c;
		i++;
	}
}

void	fuck(int sender, char c)
{
	print(c);
	if (c == 0)
	{
		g_current = -1;
		kill(sender, SIGUSR1);
	}
}

void	get_pid(int sig, siginfo_t *info, void *context)
{
	static pid_t	sender = -1;
	static int		i = 0;
	static int		c = 0;

	sender = info->si_pid;
	if (g_current == -1)
		g_current = sender;
	else if (sender != g_current)
		return ;
	(void)context;
	if (sig == SIGUSR1)
		c += power(2, i);
	if (i == 7)
	{
		fuck(sender, c);
		i = 0;
		c = 0;
	}
	else
		i++;
}

void	receiveSIG(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_pid;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	printPID();
	while (1)
	{
		receiveSIG();
		pause();
	}
}
