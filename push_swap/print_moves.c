/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:26:28 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/15 12:35:57 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_move(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp(move, "sa"))
		ft_swap(stack_a);
	else if (!ft_strcmp(move, "sb"))
		ft_swap(stack_b);
	else if (!ft_strcmp(move, "ss"))
		ft_swap_both(stack_a, stack_b);
	else if (!ft_strcmp(move, "pa"))
		ft_push(stack_a, stack_b);
	else if (!ft_strcmp(move, "pb"))
		ft_push(stack_b, stack_a);
	else if (!ft_strcmp(move, "ra"))
		ft_rotate(stack_a);
	else if (!ft_strcmp(move, "rb"))
		ft_rotate(stack_b);
	else if (!ft_strcmp(move, "rr"))
		ft_rotate_both(stack_a, stack_b);
	else if (!ft_strcmp(move, "rra"))
		ft_reverse_rotate(stack_a);
	else if (!ft_strcmp(move, "rrb"))
		ft_reverse_rotate(stack_b);
	else if (!ft_strcmp(move, "rrr"))
		ft_reverse_rotate_both(stack_a, stack_b);
	ft_putstr(move);
	ft_putchar('\n');
}
