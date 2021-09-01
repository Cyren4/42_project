/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:57:50 by cramdani          #+#    #+#             */
/*   Updated: 2021/06/17 12:46:21 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (s1 && s1[++i])
		str[i] = s1[i];
	while (s2 && s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	if (s1)
		free(s1);
	return (str);
}

char	*ft_strdup2(char *s1)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	if (s1)
		free(s1);
	return (str);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup2(""));
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start + i] && i < (unsigned int)len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
