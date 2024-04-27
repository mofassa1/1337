/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:22:32 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/23 12:13:47 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nb_is_min(int n)
{
	(void)n;
	write (1, "-2147483648", 11);
	return (11);
}

static int	printfchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	is_negative_valabs(int n, int f)
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

static int	count_digits(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	putnbr_com(int n)
{
	int	nb;
	int	i;
	int	j;
	int	printed;

	printed = 0;
	if (n == -2147483648)
		return (nb_is_min(n));
	printed = is_negative_valabs(n, 1);
	n = is_negative_valabs(n, 0);
	nb = n;
	j = -1;
	i = count_digits(n);
	printed += i;
	while (i)
	{
		while (++j < i - 1)
				nb = nb / 10;
		printfchar(nb % 10 + '0');
		nb = n;
		j = -1;
		i--;
	}
	return (printed);
}
