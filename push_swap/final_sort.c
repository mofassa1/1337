/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:52:44 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 02:13:03 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	final_sort(t_stack **stack_a)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	renisialize_index(stack_a, stack_a);
	i = get_min_value_index(*stack_a);
	if (i > size / 2)
	{
		i = size - i;
		while (i--)
			do_move(stack_a, NULL, "rra");
	}
	else
	{
		while (i--)
			do_move(stack_a, NULL, "ra");
	}
}
