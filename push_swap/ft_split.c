/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:38:27 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/24 19:33:13 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

void	free_all(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	*fill_str(char *s, int start, char c, char **s1)
{
	char	*str;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	str = (char *)malloc((j + 1) * sizeof(char));
	if (!str)
		free_all(s1, start);
	i = 0;
	while (s[start] && s[start] != c)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!str)
		exit(2);
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j++] = fill_str(s, i, c, str);
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}
