/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:37:06 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/25 18:21:17 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next)
		tmp = tmp->next;
	*stack = (*stack)->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack;
	*stack = tmp2;
}
