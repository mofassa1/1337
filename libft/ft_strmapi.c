/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:46:59 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/18 02:51:32 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sstrlen(char const *s1)
{
	int	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	i = ft_sstrlen(s);
	new_str = (char *)malloc(i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s && f && s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	while (s && s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
