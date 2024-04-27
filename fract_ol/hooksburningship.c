/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksburningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:30:26 by afadouac          #+#    #+#             */
/*   Updated: 2023/12/27 00:30:29 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook_burningship(int button, int x, int y, t_data *data)
{
	if (button == 4 || button == 5)
	{
		changement_repere(data, x, y);
		if (button == 4)
			data->zoom = 1.1;
		else if (button == 5)
			data->zoom = 1 / 1.1;
		data->shiftv *= data->zoom;
		data->plan.maxim *= data->zoom;
		data->plan.maxr *= data->zoom;
		data->plan.minim *= data->zoom;
		data->plan.minr *= data->zoom;
		generate_burningship_set(*data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

int	key_hook_burningship(int keycode, t_data *data)
{
	if (keycode == 126)
		shifting(data, 0);
	else if (keycode == 125)
		shifting(data, 1);
	else if (keycode == 124)
		shifting(data, 2);
	else if (keycode == 123)
		shifting(data, 3);
	else if (keycode == 15)
		data->color.r += 1;
	else if (keycode == 5)
		data->color.g += 1;
	else if (keycode == 11)
		data->color.b += 1;
	else if (keycode == 0)
		data->color.wb = !(data->color.wb);
	generate_burningship_set(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (keycode == 53)
		freeall(data);
	return (0);
}
