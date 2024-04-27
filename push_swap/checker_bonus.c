/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:27:59 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/27 12:18:15 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_fillstack(ac, av, &stack_a);
	if (stack_a == NULL)
		error(1, NULL);
	ft_is_doubled_or_max(stack_a);
	appliquer_operation(&stack_a, &stack_b);
	if (!stack_b && ft_issorted(stack_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
