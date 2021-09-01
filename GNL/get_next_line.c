/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:57:36 by cramdani          #+#    #+#             */
/*   Updated: 2020/02/15 19:46:23 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_clean(char *tmp)
{
	if (tmp != NULL)
		free(tmp);
	return (-1);
}

char	*lks(char *tmp)
{
	char		*leaks;

	leaks = tmp;
	tmp = ft_substr(tmp, check_n(tmp) + 1, ft_strlen(tmp));
	free(leaks);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	r = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = NULL;
	while (check_n(tmp) < 0)
	{
		if ((r = read(fd, buf, BUFFER_SIZE)) == -1)
			return (get_clean(tmp));
		buf[r] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (r == 0 && check_n(tmp) < 0)
		{
			*line = ft_substr(tmp, 0, ft_strlen(tmp));
			free(tmp);
			tmp = NULL;
			return (0);
		}
	}
	*line = ft_substr(tmp, 0, check_n(tmp));
	tmp = lks(tmp);
	return (1);
}
