/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:30:51 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/16 14:56:37 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*min_value(char *str, int n)
{
	int	i;

	if (!str)
		return (NULL);
	i = 11;
	n = n * -1;
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[0] = '-';
	str[10] = '8';
	return (str);
}

static int	is_negative(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
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

char	*ft_itoa(int n)
{
	char	*new_str;
	int		i;
	int		j;
	int		nb;

	nb = is_negative(n);
	i = count_digits(n) + nb;
	new_str = (char *)malloc((i + 1));
	if (!new_str || n == -2147483648)
		return (min_value(new_str, -2147483647));
	j = 0;
	if (nb)
		n *= -1;
	new_str[i] = '\0';
	i--;
	while (i >= 0)
	{
		new_str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (nb)
		new_str[0] = '-';
	return (new_str);
}
