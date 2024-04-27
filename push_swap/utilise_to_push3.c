/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_to_push3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 05:42:11 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/18 20:08:27 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sorted(t_stack *stack_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			i++;
		tmp = tmp->next;
	}
	if (i == 0 || (i == 1 && tmp->value < stack_a->value))
		return (1);
	return (0);
}
