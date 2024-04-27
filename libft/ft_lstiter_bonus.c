/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:41:25 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/18 15:14:25 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*courrent;

	if (lst == NULL )
		return ;
	courrent = lst;
	while (f && courrent)
	{
		f(courrent -> content);
		courrent = courrent -> next;
	}
}
