/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:12:41 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 01:32:38 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_moves_a(t_stack **stack_a, int i)
{
	int		size;

	size = ft_lstsize(*stack_a);
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

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		size;

	size = ft_lstsize(*stack_b);
	while (size--)
	{
		renisialize_index(stack_a, stack_b);
		i = get_target_a((*stack_b)->value, *stack_a);
		do_moves_a(stack_a, i);
		do_move(stack_a, stack_b, "pa");
	}
}
