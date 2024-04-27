/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:55:07 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/16 01:14:12 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
