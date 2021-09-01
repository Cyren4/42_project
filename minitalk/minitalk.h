#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
void	printPID(void);
void	send_message(pid_t pid, char *mes);
int		ft_strlen(char *s);
void	ft_putchar_fd(char c, int fd);
int		power(int i, int pow);

#endif
