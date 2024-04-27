/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:57:00 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 01:14:16 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	contain_non_flag(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->flag == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_stack	*get_best_node(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*best;
	int		min;

	min = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->flag == 0 && tmp->moves < min)
		{
			min = tmp->moves;
			best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
}

void	do_best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_data	data;

	(data).ra = 0;
	(data).rb = 0;
	(data).rr = 0;
	(data).rra = 0;
	(data).rrb = 0;
	(data).rrr = 0;
	tmp = get_best_node(*stack_a);
	fill_data(&data, tmp);
	do_moves(stack_a, stack_b, &data);
	do_move(stack_a, stack_b, "pb");
}

void	push_base(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 2;
	if (ft_lstsize(*stack_a) - count_flag(*stack_a) == 1)
		nbr = 1;
	else if (ft_lstsize(*stack_a) - count_flag(*stack_a) == 0)
		return ;
	while (i != nbr)
	{
		if (sorted(*stack_a) == 1)
			return ;
		if ((*stack_a)->flag == 0)
		{
			do_move(stack_a, stack_b, "pb");
			i++;
		}
		else if (best_move(*stack_a) == 0)
			do_move(stack_a, stack_b, "rra");
		else
			do_move(stack_a, stack_b, "ra");
	}
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (contain_non_flag(*stack_a) == 1)
	{
		renisialize_index(stack_a, stack_b);
		renisialize_index2(stack_a, stack_b);
		if (sorted(*stack_a) == 1)
			return ;
		count_moves(stack_a, stack_b);
		do_best_move(stack_a, stack_b);
	}
}
