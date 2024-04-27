/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:53 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/18 00:31:18 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sstrlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*the_return;
	size_t	i;

	i = ft_sstrlen((char *)s);
	if (i <= start)
		len = 0;
	if (i - start < len)
		len = i - start;
	the_return = (char *)malloc(sizeof(char) * (len + 1));
	if (!the_return)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		the_return[i] = s[start + i];
		i++;
	}
	the_return[i] = '\0';
	return (the_return);
}
