/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:21:38 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/17 14:29:04 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*caloc;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	i = 0;
	caloc = (char *)malloc(count * size);
	if (!caloc)
		return (NULL);
	while (i < count * size)
	{
		caloc[i] = 0;
	i++;
	}
	return ((void *)caloc);
}
