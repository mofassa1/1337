/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:16:48 by afadouac          #+#    #+#             */
/*   Updated: 2024/01/12 16:23:58 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	*free_all(char **str, int nbs)
{
	int	i;

	i = -1;
	while (++i < nbs)
		free(str[i]);
	free(str);
	return (NULL);
}

static int	ft_count_words(const char *str, char sep)
{
	int	i;
	int	wnbr;
	int	len;

	if (!str)
		return (0);
	len = ft_strlen ((char *)str);
	i = -1;
	wnbr = 0;
	while (++i < len)
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			wnbr++;
	return (wnbr);
}

static int	size_septosep(const char *str, char sep, int word, int f)
{
	int	i;
	int	len;
	int	wordi;

	if (!str || (!str && !sep))
		return (0);
	if (!sep)
		return (ft_strlen((char *)str) + 1);
	i = -1;
	wordi = 0;
	len = 0;
	while (str[++i])
	{
		if ((str[i] == sep && str[i + 1] != sep)
			|| (str[i] != sep && i == 0))
			wordi++;
		if (str[i] != sep && wordi == word)
			len++;
		if (word == wordi && f)
			return (i + 1);
	}
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		i;
	int		nbwords;
	int		size_str;

	i = -1;
	nbwords = ft_count_words(s, c);
	new_str = (char **)malloc((nbwords + 1) * sizeof(char *));
	if (!new_str)
		return (free_all(new_str, 0));
	while (++i < nbwords)
	{
		size_str = size_septosep(s, c, i + 1, 0);
		new_str[i] = (char *)malloc(size_str);
		if (!new_str)
			return (free_all(new_str, size_str));
		if (!i && s[0] != c)
			ft_strlcpy(new_str[i], s, size_str);
		else
			ft_strlcpy(new_str[i], s + size_septosep(s, c, i + 1, 1), size_str);
	}
	new_str[i] = NULL;
	return (new_str);
}
