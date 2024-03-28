/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:32:04 by pablogon          #+#    #+#             */
/*   Updated: 2024/03/06 22:11:06 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char			*ret;
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	ret = malloc(sizeof(char) * ((len1 + len2) + 1));
	if (!ret)
		return (0);
	while (str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	while (str2[i - len1])
	{
		ret[i] = str2[i - len1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_searchnewline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	if (str[i] == 0)
	{
		return (-1);
	}
	return (i);
}

static char	*ft_savememoryifstorageisnull(char *storage)
{
	if (storage == NULL)
	{
		storage = malloc(sizeof(char) * (1));
		if (!storage)
			return (NULL);
		*storage = '\0';
	}
	return (storage);
}

static char	*ft_extractline(char **storage, int findnewline)
{
	char	*newstorage;
	char	*line;

	line = ft_substr (*storage, 0, findnewline + 1);
	if (!line)
		return (ft_freestorage(storage));
	newstorage = ft_strdup(&(*storage)[findnewline + 1]);
	free (*storage);
	*storage = newstorage;
	if (!*storage)
		return (ft_freestorage(&line));
	return (line);
}

char	*get_next_line(int fd)
{
	int				findnewline;
	static char		*storage[FD_SETSIZE];
	char			*aux;

	if (fd < 0)
		return (NULL);
	storage[fd] = ft_savememoryifstorageisnull (storage[fd]);
	if (storage[fd])
		storage[fd] = ft_readifdonthavenewline (storage[fd], fd);
	if (storage[fd] == NULL)
		return (NULL);
	findnewline = ft_searchnewline(storage[fd]);
	if (findnewline == -1)
	{
		aux = ft_strdup(storage[fd]);
		free (storage[fd]);
		storage[fd] = NULL;
		return (aux);
	}
	return (ft_extractline(&storage[fd], findnewline));
}
