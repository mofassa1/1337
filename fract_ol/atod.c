/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:30:43 by afadouac          #+#    #+#             */
/*   Updated: 2023/12/26 20:30:47 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] != '.')
		{
			result *= 10;
			result += str[i] - '0';
		}
		i++;
	}
	return ((result * sign));
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	point_position(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '.' )
			return (ft_strlen(str) - i - 1);
	return (0);
}

double	ft_atod(char *str)
{
	double	result;
	int		i;
	int		the_point_position;

	i = 0;
	result = 0;
	result = ft_atoi(str);
	the_point_position = point_position(str);
	while (the_point_position)
	{
		result /= 10;
		the_point_position--;
	}
	return (result);
}
