/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:16:21 by pablogon          #+#    #+#             */
/*   Updated: 2024/03/04 21:01:39 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

char			*ft_strjoin(char *str1, char *str2);
unsigned int	ft_strlen(char *s);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
char			*ft_readifdonthavenewline(char *storage, int fd);
int				ft_searchnewline(char *str);
char			*get_next_line(int fd);
char			*ft_freestorage(char **storage);

#endif 