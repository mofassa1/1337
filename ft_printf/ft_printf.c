/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:51:49 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/23 22:47:47 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (write(1, "(null)", 6));
	while (s && s[++i])
		write(1, &s[i], 1);
	return (i);
}

static int	ft_printfchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_data(char c, va_list arg_listt)
{
	int	i;

	i = 0;
	if (c == '%')
		i += ft_printfchar('%');
	else if (c == 'c')
		i += ft_printfchar(va_arg(arg_listt, int));
	else if (c == 's')
		i += print_str(va_arg(arg_listt, char *));
	else if (c == 'd' || c == 'i')
		i += putnbr_com(va_arg(arg_listt, int));
	else if (c == 'u')
		i += printn_base(va_arg(arg_listt, unsigned int), "0123456789");
	else if (c == 'x')
		i += printn_base(va_arg(arg_listt, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		i += printn_base(va_arg(arg_listt, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		write(1, "0x", 2);
			i = 2;
		i += printn_base(va_arg(arg_listt, size_t), "0123456789abcdef");
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg_list;
	int		char_printed;
	int		i;

	i = 0;
	char_printed = 0;
	va_start(arg_list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!s[i + 1])
				break ;
			char_printed += print_data(s[i + 1], arg_list);
		i++;
		}
		else
		{
			write(1, &s[i], 1);
			char_printed++;
		}
	i++;
	}
	va_end(arg_list);
	return (char_printed);
}
