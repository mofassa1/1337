/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:54:17 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/18 23:35:08 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*fill_array_one(int *arr, t_stack *stack_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(stack_a);
	while (i < size)
	{
		arr[i] = 1;
		i++;
	}
	return (arr);
}

t_stack	*get_node_by_index(t_stack *stack, int index)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	*ft_get_factors(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;
	int		size;
	int		*arr;

	size = ft_lstsize(stack_a);
	j = stack_a->next;
	i = stack_a;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		errors(2, &stack_a);
	arr = fill_array_one(arr, stack_a);
	while (j)
	{
		while (i->index < j->index)
		{
			if (i->value < j->value)
				arr[j->index] = max_of(arr[j->index], arr[i->index] + 1);
			i = i->next;
		}
		i = stack_a;
		j = j->next;
	}
	return (arr);
}

void	ft_putflag(t_stack *stack, int *arr)
{
	t_stack	*tmp;
	int		size;
	int		i;
	int		last_i;

	i = 0;
	size = ft_lstsize(stack);
	i = get_max_value_index(arr, size);
	last_i = i;
	tmp = get_node_by_index(stack, i);
	tmp->flag = 1;
	i--;
	while (stack && i >= 0)
	{
		if (stack && arr[i] == arr[last_i] - 1)
		{
			tmp = get_node_by_index(stack, i);
			if (tmp == NULL)
				return ;
			tmp->flag = 1;
			last_i = i;
		}
		i--;
	}
}

void	flag_longest(t_stack *stack_a)
{
	int	*arr;

	if (sorted(stack_a) == 1)
		return ;
	arr = ft_get_factors(stack_a);
	ft_putflag(stack_a, arr);
	free(arr);
}
