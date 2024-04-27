/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:17:11 by afadouac          #+#    #+#             */
/*   Updated: 2023/12/25 18:17:14 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init(t_data *data, char *str[])
{
	if (str[2] && str[3])
	{
		data->c.real = ft_atod(str[2]);
		data->c.imag = ft_atod(str[3]);
	}
	data->mouse.real = 0;
	data->mouse.imag = 0;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, str[1]);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_string_put(data->mlx, data->win, W, H, 255, "welcome to fractol world");
	mlx_string_put(data->mlx, data->win, W, H + 20, 255, "scrol for zoom");
	mlx_string_put(data->mlx, data->win, W, H + 40, 255, "rgba for colors");
	mlx_string_put(data->mlx, data->win, W, H + 60, 255, "up down... to move");
	data->plan.maxim = 2.0;
	data->plan.maxr = 2.0;
	data->plan.minim = -2.0;
	data->plan.minr = -2.0;
	data->shiftv = 1.;
	data->zoom = 1.0;
	data->color.r = 10;
	data->color.g = 9;
	data->color.b = 1;
	data->color.wb = 1;
}

t_complex	complex(int x, int y, t_data data)
{
	t_complex	z;

	z.real = (data.plan.minr + (x * \
		(data.plan.maxr - data.plan.minr) / WIDTH));
	z.imag = (data.plan.maxim + (y * \
		(data.plan.minim - data.plan.maxim) / HEIGHT));
	return (z);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	changement_repere(t_data *data, int x, int y)
{
	t_complex	tmp;

	if (complex(x, y, *data).imag != 0 && complex(x, y, *data).real != 0)
	{
		tmp = complex(x, y, *data);
		data->mouse.real += tmp.real;
		data->mouse.imag += tmp.imag;
		data->plan.maxim -= tmp.imag;
		data->plan.maxr -= tmp.real;
		data->plan.minim -= tmp.imag;
		data->plan.minr -= tmp.real;
	}
}

void	shifting(t_data *data, int i)
{
	if (i == 0)
	{
		data->plan.maxim -= data->shiftv;
		data->plan.minim -= data->shiftv;
	}
	else if (i == 1)
	{
		data->plan.maxim += data->shiftv;
		data->plan.minim += data->shiftv;
	}
	else if (i == 2)
	{
		data->plan.maxr -= data->shiftv;
		data->plan.minr -= data->shiftv;
	}
	else if (i == 3)
	{
		data->plan.maxr += data->shiftv;
		data->plan.minr += data->shiftv;
	}
}
