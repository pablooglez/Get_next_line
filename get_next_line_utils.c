/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:16:07 by pablogon          #+#    #+#             */
/*   Updated: 2024/03/04 21:30:03 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*str;
	unsigned int	m_len;
	unsigned int	i;

	i = 0;
	if (start > ft_strlen(s))
		m_len = 0;
	else
		m_len = ft_strlen(s) - start;
	if (len > m_len)
		len = m_len;
	len += 1;
	str = (char *)malloc(len);
	if (str == NULL)
		return (NULL);
	while (s[i] && --len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_freestorage(char **storage)
{
	free(*storage);
	*storage = NULL;
	return (NULL);
}

char	*ft_readifdonthavenewline(char *storage, int fd)
{
	int		bytesread;
	char	buffer[BUFFER_SIZE + 1];
	char	*new;

	while (ft_searchnewline(storage) == -1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (ft_freestorage(&storage));
		buffer[bytesread] = '\0';
		if (buffer[0] == '\0')
		{
			if (storage[0] == '\0')
				return (ft_freestorage(&storage));
			return (storage);
		}
		new = ft_strjoin(storage, buffer);
		if (!new)
			return (ft_freestorage(&storage));
		free (storage);
		storage = new;
	}
	return (storage);
}
