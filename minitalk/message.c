#include "minitalk.h"

void	send_bit(pid_t pid, int i)
{
	int	ret;

	if (i)
		ret = kill(pid, SIGUSR1);
	else
		ret = kill(pid, SIGUSR2);
	if (ret == -1)
	{
		write(1, "Erreur: Envoie du signal echoue\n", 33);
		exit(EXIT_FAILURE);
	}
	usleep(100);
}

void	send_char(pid_t pid, char c)
{
	send_bit(pid, c & 1);
	send_bit(pid, c & 2);
	send_bit(pid, c & 4);
	send_bit(pid, c & 8);
	send_bit(pid, c & 16);
	send_bit(pid, c & 32);
	send_bit(pid, c & 64);
	send_bit(pid, c & 128);
}

void	send_message(pid_t pid, char *mes)
{
	while (*mes)
	{
		send_char(pid, *mes);
		mes++;
	}
	send_char(pid, *mes);
}
