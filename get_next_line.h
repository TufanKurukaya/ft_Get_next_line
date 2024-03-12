/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:52:26 by tkurukay          #+#    #+#             */
/*   Updated: 2024/02/02 12:35:40 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strdup(char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s, const char *s1);
void	*ft_free_save(char **save, int create_line);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif