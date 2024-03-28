/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:16:15 by pablogon          #+#    #+#             */
/*   Updated: 2024/03/04 21:31:17 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*storage;
	char			*aux;

	if (fd < 0)
		return (NULL);
	storage = ft_savememoryifstorageisnull (storage);
	if (storage)
		storage = ft_readifdonthavenewline (storage, fd);
	if (storage == NULL)
		return (NULL);
	findnewline = ft_searchnewline(storage);
	if (findnewline == -1)
	{
		aux = ft_strdup(storage);
		free (storage);
		storage = NULL;
		return (aux);
	}
	return (ft_extractline(&storage, findnewline));
}
