/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_to_push_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:02:19 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 20:19:28 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_min_value_index(t_stack *stack_a)
{
	t_stack	*tmp;
	int		min;
	int		i;

	min = INT_MAX;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			i = tmp->index;
		}
		tmp = tmp->next;
	}
	return (i);
}

int	get_target_a(int value, t_stack *stack_a)
{
	t_stack	*tmp;
	int		min;
	int		i;

	min = INT_MAX;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value > value && tmp->value < min)
		{
			min = tmp->value;
			i = tmp->index;
		}
		tmp = tmp->next;
	}
	if (min == INT_MAX)
		i = get_min_value_index(stack_a);
	return (i);
}
