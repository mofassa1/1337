/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:45:39 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/27 14:26:04 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	complete_triple(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		k;

	tmp = *stack;
	i = tmp->value;
	j = tmp->next->value;
	k = tmp->next->next->value;
	if (i > j && j < k)
		do_move(stack, NULL, "ra");
	else if (i > j && j > k)
	{
		do_move(stack, NULL, "sa");
		do_move(stack, NULL, "rra");
	}
}

void	sort_triple(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		k;

	tmp = *stack;
	i = tmp->value;
	j = tmp->next->value;
	k = tmp->next->next->value;
	if (i < j && j > k && k > i)
	{
		do_move(stack, NULL, "rra");
		do_move(stack, NULL, "sa");
	}
	else if (i < j && j > k && k < i)
		do_move(stack, NULL, "rra");
	else if (i > j && j < k && k > i)
		do_move(stack, NULL, "sa");
	else
		complete_triple(stack);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (sorted(*stack_a))
		return ;
	tmp = *stack_a;
	tmp2 = *stack_b;
	do_move(stack_a, stack_b, "pb");
	if (sorted(*stack_a))
		return ;
	do_move(stack_a, stack_b, "pb");
	sort_triple(stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_fillstack(ac, av, &stack_a);
	if (stack_a == NULL)
		return (1);
	ft_is_doubled_or_max(stack_a);
	if (ft_lstsize(stack_a) == 3)
		sort_triple(&stack_a);
	else if (ft_lstsize(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	ft_is_sorted(stack_a, stack_b);
	flag_longest(stack_a);
	push_base(&stack_a, &stack_b);
	push_to_b(&stack_a, &stack_b);
	push_to_a(&stack_a, &stack_b);
	final_sort(&stack_a);
	ft_is_sorted(stack_a, NULL);
	do_move(&stack_a, NULL, "ra");
	ft_lstclear(&stack_a);
	return (0);
}
