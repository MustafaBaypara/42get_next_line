/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:15:03 by mbaypara          #+#    #+#             */
/*   Updated: 2024/01/18 15:35:37 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	int		i;

	i = 0;
	len = ft_strlen(s) + 1;
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	while (*s)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	slen;

	slen = ft_strlen(s);
	if (!s || len <= 0)
		return (NULL);
	if (len > slen)
		len = slen;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (i < slen && j < len)
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	*free_stash(char **stash, int cline)
{
	char	*line;

	if (!*stash)
		return (NULL);
	if (cline == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	else if (cline == 1)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	return (NULL);
}
