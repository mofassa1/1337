/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:06:01 by afadouac          #+#    #+#             */
/*   Updated: 2024/01/15 21:06:05 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*maloc;

	i = 0;
	while (s1[i])
		i++;
	maloc = (char *)malloc((i + 1) * sizeof(char));
	if (!maloc)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		maloc[i] = s1[i];
		i++;
	}
	maloc[i] = '\0';
	return (maloc);
}

static int	ft_sstrlen(char const *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = ft_sstrlen(s1) + ft_sstrlen(s2);
	new_str = (char *)malloc(i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned char)s2[i] > (unsigned char)s1[i])
			return (-1);
		if ((unsigned char)s2[i] < (unsigned char)s1[i])
			return (1);
		i++;
	}
	if (i < n && (s1[i] || s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
