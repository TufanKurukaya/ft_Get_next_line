/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:52:40 by tkurukay          #+#    #+#             */
/*   Updated: 2024/02/02 12:34:18 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_copy(char *s1, char *s2)
{
	char	*str;

	if (!s1 && s2)
	{
		str = ft_strdup(s2);
		if (!str)
			return (NULL);
		return (str);
	}
	str = ft_strjoin(s1, s2);
	ft_free_save(&s1, 0);
	return (str);
}

static int	ft_find_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == '\n')
			return (i + 1);
	return (0);
}

static char	*ft_before_nl(char *str)
{
	char	*line;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_find_nl(str);
	if (!j)
		j = ft_strlen(str);
	line = malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	while (i < j)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_after_nl(char *str)
{
	char	*line;
	int		i;

	if (!str)
		return (NULL);
	i = ft_find_nl(str);
	if (str[i] == '\0')
		return (ft_free_save(&str, 0));
	line = ft_substr(str, i, ft_strlen(str));
	if (!line)
		return (ft_free_save(&str, 0));
	ft_free_save(&str, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	static char	*save = NULL;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret <= 0 && !save) || ret == -1)
			return (ft_free_save(&save, 0));
		buf[ret] = '\0';
		save = ft_copy(save, buf);
		if (ft_find_nl(save))
		{
			line = ft_before_nl(save);
			if (!line)
				return (ft_free_save(&save, 0));
			return (save = ft_after_nl(save), line);
		}
	}
	return (ft_free_save(&save, 1));
}
