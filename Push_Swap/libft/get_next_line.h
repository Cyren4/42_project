/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:58:14 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/17 12:46:13 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
char	*lks(char *tmp);
int		check_n(char *line);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup2(char *s1);
char	*ft_substr2(char *s, unsigned int start, size_t len);

#endif
