/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:27:48 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/27 00:38:37 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_issorted(t_stack *stack)
{
	t_stack	*tmp;

	if ((stack) != NULL && (stack)->next == NULL)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
		{
			ft_lstclear(&stack);
			return (0);
		}
		tmp = tmp->next;
	}
	ft_lstclear(&stack);
	return (1);
}

void	appliquer_operation2(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "rb\n") == 0)
		do_move(stack_a, stack_b, "rb");
	else if (ft_strcmp(line, "rr\n") == 0)
		do_move(stack_a, stack_b, "rr");
	else if (ft_strcmp(line, "rra\n") == 0)
		do_move(stack_a, stack_b, "rra");
	else if (ft_strcmp(line, "rrb\n") == 0)
		do_move(stack_a, stack_b, "rrb");
	else if (ft_strcmp(line, "rrr\n") == 0)
		do_move(stack_a, stack_b, "rrr");
	else
	{
		if (*stack_b)
			ft_lstclear(stack_b);
		error(2, stack_a);
	}
}

void	appliquer_operation(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa\n") == 0)
			do_move(stack_a, stack_b, "sa");
		else if (ft_strcmp(line, "sb\n") == 0)
			do_move(stack_a, stack_b, "sb");
		else if (ft_strcmp(line, "ss\n") == 0)
			do_move(stack_a, stack_b, "ss");
		else if (ft_strcmp(line, "pa\n") == 0)
			do_move(stack_a, stack_b, "pa");
		else if (ft_strcmp(line, "pb\n") == 0)
			do_move(stack_a, stack_b, "pb");
		else if (ft_strcmp(line, "ra\n") == 0)
			do_move(stack_a, stack_b, "ra");
		else
			appliquer_operation2(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}
