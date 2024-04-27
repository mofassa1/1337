/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:29:51 by afadouac          #+#    #+#             */
/*   Updated: 2023/12/27 00:29:54 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	get_color_burningship(t_complex z1, t_data data)
{
	t_complex	z;
	double		temp_real;
	int			iter;

	iter = 0;
	z.imag = 0;
	z.real = 0;
	z1.imag += data.mouse.imag;
	z1.real += data.mouse.real;
	while (iter < 150 && z.real * z.real + z.imag * z.imag <= 4)
	{
		temp_real = (z.real * z.real - z.imag * z.imag + z1.real);
		z.imag = (-2 * fabs(z.real * z.imag) + z1.imag);
		z.real = temp_real;
		iter++;
	}
	if (iter == 150)
		return (data.color.wb * 0x00ffffff);
	else
		return ((((iter * data.color.r) % 256 << 16))
			| (((iter * data.color.g) % 256 << 8))
			| ((iter * data.color.b) % 256));
}

void	generate_burningship_set(t_data data)
{
	int	x;
	int	color;
	int	y;

	x = 0;
	mlx_clear_window(data.mlx, data.win);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color = get_color_burningship(complex(x, y, data), data);
			my_mlx_pixel_put(&data, x, y, color);
			y++;
		}
		x++;
	}
}
