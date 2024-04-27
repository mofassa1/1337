/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_topush2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:50:53 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 20:22:17 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	best_move2(int size, int index, int index2)
{
	if (index <= size / 2 && index2 <= size / 2)
		return (1);
	if (index > size / 2 && index2 > size / 2)
		return (0);
	if (index <= size - index2)
		return (1);
	return (0);
}

int	best_move(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		index;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->flag == 0)
		{
			index = tmp->index;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->flag == 0)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	return (best_move2(ft_lstsize(stack_a), tmp2->index, index));
}

void	do_moves(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	while (data->rrr--)
		do_move(stack_a, stack_b, "rrr");
	while (data->rra--)
		do_move(stack_a, stack_b, "rra");
	while (data->rrb--)
		do_move(stack_a, stack_b, "rrb");
	while (data->ra--)
		do_move(stack_a, stack_b, "ra");
	while (data->rr--)
		do_move(stack_a, stack_b, "rr");
	while (data->rb--)
		do_move(stack_a, stack_b, "rb");
}

void	fill_data(t_data *data, t_stack *node)
{
	if (node->index2 <= 0 && node->target <= 0)
	{
		(data)->rrr = min_of(abs(node->index2), abs(node->target));
		(data)->rra = abs(node->index2) - (data)->rrr;
		(data)->rrb = abs(node->target) - (data)->rrr;
	}
	if (node->index2 >= 0 && node->target >= 0)
	{
		(data)->rr = min_of((node->index2), (node->target));
		(data)->ra = (node->index2) - (data)->rr;
		(data)->rb = (node->target) - (data)->rr;
	}
	if (node->index2 <= 0 && node->target >= 0)
	{
		(data)->rra = abs(node->index2);
		(data)->rb = node->target;
	}
	if (node->index2 >= 0 && node->target <= 0)
	{
		(data)->ra = node->index2;
		(data)->rrb = abs(node->target);
	}
}

int	count_moves_a(t_stack *a, t_stack *b)
{
	if (a->index2 * b->index2 < 0)
		return (abs(a->index2) + abs(b->index2));
	else
		return (max_of(abs(a->index2), abs(b->index2)));
}
