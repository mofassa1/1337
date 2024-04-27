/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_node_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:35:18 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/24 21:44:14 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstclear(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || stack == NULL)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*courrent;

	courrent = lst;
	while (lst && courrent -> next != NULL)
		courrent = courrent->next;
	return (courrent);
}

t_stack	*ft_lstnew(long content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL )
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node -> next = new;
}
