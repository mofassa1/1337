/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printn_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:59:33 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/23 14:05:19 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	printfchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static long	is_negative_valabs(size_t n, int f)
{
	if (n < 0)
	{
		if (f)
			return (1);
		write(1, "-", 1);
		return (n * -1);
	}
	if (f)
		return (0);
	return (n);
}

static int	count_digits(size_t nb, char *base)
{
	int	i;
	int	len_base;

	i = 0;
	len_base = ft_strlen(base);
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / len_base;
		i++;
	}
	return (i);
}

int	printn_base(size_t n, char *base)
{
	int		i;
	int		j;
	size_t	nb;
	int		printed;

	printed = is_negative_valabs(n, 1);
	n = is_negative_valabs(n, 0);
	nb = n;
	j = -1;
	i = count_digits(n, base);
	printed += i;
	while (i)
	{
		while (++j < i - 1)
				nb = nb / ft_strlen(base);
		printfchar(base[(nb % ft_strlen(base))]);
		nb = n;
		j = -1;
		i--;
	}
	return (printed);
}
