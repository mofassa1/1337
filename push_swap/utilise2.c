/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:59:25 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/19 03:59:39 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_flag(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->flag == 1)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	*ft_substr(int const *s, unsigned int start, size_t len)
{
	int		*the_return;
	size_t	i;

	i = sizeof(*s) / sizeof(s[0]);
	if (i <= start)
		len = 0;
	if (i - start < len)
		len = i - start;
	the_return = (int *)malloc(sizeof(int) * (len + 1));
	if (!the_return)
		return (NULL);
	i = 0;
	while (i < len)
	{
		the_return[i] = s[start + i];
		i++;
	}
	the_return[i] = '\0';
	return (the_return);
}

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
