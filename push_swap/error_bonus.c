/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:52:51 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 20:08:25 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(int error, t_stack **stack_a)
{
	ft_putstr("error\n");
	if (error == 2)
		ft_lstclear(stack_a);
	exit(1);
}
