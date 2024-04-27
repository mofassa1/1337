/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:29:02 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 05:49:27 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s2[i] > (unsigned char)s1[i])
			return (-1);
		if ((unsigned char)s2[i] < (unsigned char)s1[i])
			return (1);
		i++;
	}
	if ((s1[i] || s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

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
		j = 0;
		while (tab[j])
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(tab[j])));
			j++;
		}
		free_tab(tab);
		i++;
	}
	return (*stack_a);
}
