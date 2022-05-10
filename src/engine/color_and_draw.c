/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:28:47 by tjairus           #+#    #+#             */
/*   Updated: 2022/03/28 09:45:46 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	setup_color(t_data *env)
{
	env->c.cent = 127;
	env->c.wid = 128;
	env->c.r_freq = 0.33;
	env->c.g_freq = 0.33;
	env->c.b_freq = 0.33;
	env->c.r_phase = 0.0;
	env->c.g_phase = (2 * M_PI) / 3;
	env->c.b_phase = (4 * M_PI) / 3;
	env->c.color_index = 4;
	env->c.palette = 1;
	env->c.is_rainbow = 0;
}
/* this part is inspired by https://krazydad.com//tutorials/makecolors.php */
/* a way to get repeating rainbow colors */

int	get_color(t_data *m, int i, t_numbr new)
{
	int		r;
	int		g;
	int		b;
	t_color	c;

	c = m->c;
	if (i >= m->i)
		return (0);
	else if (m->c.is_rainbow == 1)
	{
		r = sin(fmod(c.r_freq * i + c.r_phase, 2 * M_PI)) * c.wid + c.cent;
		g = sin(fmod(c.g_freq * i + c.g_phase, 2 * M_PI)) * c.wid + c.cent;
		b = sin(fmod(c.b_freq * i + c.b_phase, 2 * M_PI)) * c.wid + c.cent;
		return (r << 16 | g << 8 | b);
	}
	else
		return (get_color2(m, i, new));
	return (0);
}

int	get_color2(t_data *m, int i, t_numbr new)
{
	int		color;
	float	cont_index;
	double	real;
	double	img;

	real = new.real;
	img = new.img;
	if (i >= m->i)
		return (0);
	if (m->type == 2)
		cont_index = i * 4 + 2 - (log(2) / fabs(real * real + img
					* img)) / log (2);
	else
		cont_index = i + 1 - (log(2) / fabs(real * real + img * img)) / log (2);
	color = m->c.color_index * cont_index + m->c.palette;
	return (color);
}

void	ft_draw_fractal(t_data *data)
{
	if (data->type == 1)
		mandelbrot(data);
	else if (data->type == 2)
		julia(data);
	else if (data->type == 3)
		ship(data);
}
