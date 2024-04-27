/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_bonus3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:33:32 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/27 14:25:38 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_is_doubled_or_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == 2147483648)
			error(2, &stack);
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				error(2, &stack);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

long	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (2147483648);
		i++;
	}
	if (str[0] == '\0' || result * sign > INT_MAX || \
		str[i] != '\0' || result * sign < INT_MIN || \
		((str[0] == '-' || str[0] == '+') && str[1] == '\0'))
		return (2147483648);
	return ((result * sign));
}
