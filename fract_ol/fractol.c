/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 00:31:33 by afadouac          #+#    #+#             */
/*   Updated: 2023/12/23 00:31:41 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	is_valid_in(int ac, char *av[])
{
	if (!((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) \
		|| (ac == 4 && !ft_strcmp(av[1], "julia")) \
		|| (ac == 2 && !ft_strcmp(av[1], "burningship"))) \
		|| (ac == 4 && (!is_valid(av[2]) || !is_valid(av[3]))))
	{
		ft_putstr("invalid input !\ninput must be :\n");
		ft_putstr("for mandelbrot : ./fract_ol mandelbrot\n");
		ft_putstr("for julia : ./fract_ol julia");
		ft_putstr(" <float c.real> <float  c.imag>\n");
		ft_putstr("for burningship : ./fract_ol burningship\n");
		exit (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (is_valid_in(ac, av))
	{
		data.mlx = mlx_init();
		init(&data, av);
		if (ac == 2 && av[1][0] == 'b')
		{
			mlx_mouse_hook(data.win, &mouse_hook_burningship, &data);
			mlx_key_hook(data.win, key_hook_burningship, &data);
		}
		if (ac == 2 && av[1][0] == 'm')
		{
			mlx_mouse_hook(data.win, &mouse_hook, &data);
			mlx_key_hook(data.win, key_hook, &data);
		}
		else if (ac == 4)
		{
			mlx_mouse_hook(data.win, &mouse_hook_julia, &data);
			mlx_key_hook(data.win, key_hook_julia, &data);
		}
	}
	mlx_hook(data.win, 17, 1L << 15, freeall, &data);
	mlx_loop(data.mlx);
	return (0);
}
