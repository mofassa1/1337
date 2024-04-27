/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:35:17 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/27 14:26:19 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	errors(int error, t_stack **stack_a)
{
	ft_putstr("error\n");
	if (error == 2)
		ft_lstclear(stack_a);
	exit(255);
}
