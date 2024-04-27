/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_topush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:17:40 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 01:49:42 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	renisialize_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	renisialize_index2(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		size;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	while (tmp)
	{
		if (tmp->index > size / 2)
			tmp->index2 = tmp->index - size;
		else
			tmp->index2 = tmp->index;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	size = ft_lstsize(*stack_b);
	while (tmp)
	{
		if (tmp->index > size / 2)
			tmp->index2 = tmp->index - size;
		else
			tmp->index2 = tmp->index;
		tmp = tmp->next;
	}
}

int	ft_get_max_value_index(t_stack *stack_b)
{
	t_stack	*tmp;
	int		begger;
	int		index;

	tmp = stack_b;
	begger = INT_MIN;
	index = INT_MIN;
	while (tmp)
	{
		if (tmp->value > begger)
		{
			index = tmp->index;
			begger = tmp->value;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	get_target(int value, t_stack *stack_b)
{
	t_stack	*tmp;
	int		begger;
	int		index;

	tmp = stack_b;
	begger = INT_MIN;
	index = INT_MIN;
	while (tmp)
	{
		if (tmp->value <= value && tmp->value > begger)
		{
			index = tmp->index;
			begger = tmp->value;
		}
		tmp = tmp->next;
	}
	if (index == INT_MIN)
	{
		index = ft_get_max_value_index(stack_b);
	}
	return (index);
}

void	count_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*node;
	int		index;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->flag == 0)
		{
			index = get_target(tmp->value, *stack_b);
			node = get_node_by_index(*stack_b, index);
			tmp->moves = count_moves_a(tmp, node);
			tmp->target = node->index2;
		}
		tmp = tmp->next;
	}
}
