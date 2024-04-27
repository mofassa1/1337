/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:55:51 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/16 01:03:33 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		return (n * -1);
	}
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

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	j;
	int	nb;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	n = is_negative(n, fd);
	nb = n;
	j = -1;
	i = count_digits(n);
	while (i)
	{
		while (++j < i - 1)
				nb = nb / 10;
		ft_putchar_fd(nb % 10 + '0', fd);
		nb = n;
		j = -1;
		i--;
	}
}
