/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comarison.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:43:46 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/22 13:47:51 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	max_of(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_of(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
