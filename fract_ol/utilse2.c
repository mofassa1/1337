/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:36:29 by afadouac          #+#    #+#             */
/*   Updated: 2023/12/25 22:36:32 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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

int	is_valid(char *str)
{
	int	i;
	int	count_point;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	i--;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			if (str[i] != '.' || str[0] == '.')
				return (0);
	i = 0;
	count_point = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count_point++;
		i++;
	}
	if (count_point > 1)
		return (0);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	freeall(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit (0);
}
