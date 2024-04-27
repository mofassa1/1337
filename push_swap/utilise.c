/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:36:36 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/24 19:43:14 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_stack	*ft_fillstack(int ac, char **av, t_stack **stack_a)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	i = 1;
	index = 0;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		if (tab[0] == '\0')
			errors(1, stack_a);
		j = 0;
		while (tab[j])
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(tab[j]), index++));
			j++;
		}
		free_tab(tab);
		i++;
	}
	return (*stack_a);
}
