/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 00:31:06 by afadouac          #+#    #+#             */
/*   Updated: 2023/12/23 00:31:17 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <string.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 720
# define W 300
# define H 200

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_planc
{
	double	minr;
	double	minim;
	double	maxr;
	double	maxim;
}			t_planc;

typedef struct s_color
{
	int	wb;
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	double		shiftv;
	t_color		color;
	t_planc		plan;
	t_complex	c;
	t_complex	mouse;
}				t_data;

void		generate_julia_set(t_data data);
void		generate_mandelbrot_set(t_data data);
void		generate_burningship_set(t_data data);
int			get_color_julia(t_complex z, t_data data);
int			get_color(t_complex z1, t_data data);
int			get_color_burningship(t_complex z1, t_data data);
int			key_hook_julia(int keycode, t_data *data);
int			key_hook_burningship(int keycode, t_data *data);
int			key_hook(int keycode, t_data *data);
int			mouse_hook_burningship(int button, int x, int y, t_data *data);
int			mouse_hook_julia(int button, int x, int y, t_data *data);
int			mouse_hook(int button, int x, int y, t_data *data);
t_complex	complex(int x, int y, t_data data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		init(t_data *data, char *str[]);
int			ft_strcmp(const char *s1, const char *s2);
void		changement_repere(t_data *data, int x, int y);
void		shifting(t_data *data, int i);
double		ft_atod(char *str);
void		ft_putstr(char *str);
int			is_valid(char *str);
int			is_valid_in(int ac, char *av[]);
int			freeall(t_data *data);
#endif
