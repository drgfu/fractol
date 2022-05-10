/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:30:48 by tjairus           #+#    #+#             */
/*   Updated: 2022/03/28 09:26:14 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

/* Keycode values from */
/*https://developer.mozilla.org/en-US/docs/Web/API/KeyboardEvent/  */
/*code/code_values*/
int	ft_key_hook(int code, t_data *data)
{
	if (code == 65307)
		the_end(data);
	if (code == 65362)
		ft_mmove(data, data->x / 2, data->y / 2 + data->y / 16, 0.1);
	if (code == 65364)
		ft_mmove(data, data->x / 2, data->y / 2 - data->y / 16, 0.1);
	if (code == 65361)
		ft_mmove(data, data->x / 2 + data->x / 16, data->y / 2, 0.1);
	if (code == 65363)
		ft_mmove(data, data->x / 2 - data->x / 16, data->y / 2, 0.1);
	if (code == 0x0020)
	{	
		ft_putendl_fd("Use mouse to zoom and arrow keys to move around", 1);
		ft_putendl_fd("A-set color, D-change palette", 1);
		ft_putendl_fd("S-switch rainbow colors on and off", 1);
		ft_putendl_fd("In rainbow mode to change colors:", 1);
		ft_putendl_fd("1-red, 2-green, 3-blue", 1);
		ft_putendl_fd("W- reset color, Esc- to quit", 1);
	}
	ft_key_hook_color(code, data);
	ft_rgb_switch_hook(code, data);
	ft_draw_fractal(data);
	return (code);
}

int	ft_key_hook_color(int code, t_data *data)
{
	if (code == 0x0061)
	{
		if (data->c.color_index < 10)
			data->c.color_index = data->c.color_index + 3;
		else
			data->c.color_index = 3;
	}
	if (code == 0x0073)
	{
		if (data->c.is_rainbow == 1)
			data->c.is_rainbow = 0;
		else
			data->c.is_rainbow = 1;
	}
	if (code == 0x0077)
		setup_color(data);
	if (code == 0x0064)
	{
		if (data->c.palette < 256 * 256 * 256 * 127)
			data->c.palette *= 127;
		else
			setup_color(data);
	}	
	return (1);
}

int	ft_rgb_switch_hook(int code, t_data *data)
{
	if (code == 0x0031)
	{
		if (data->c.r_freq < 0.56)
			data->c.r_freq += 0.11;
		else
			data->c.r_freq = 0;
	}
	if (code == 0x0032)
	{
		if (data->c.g_freq < 0.56)
			data->c.g_freq += 0.11;
		else
			data->c.g_freq = 0;
	}
	if (code == 0x0033)
	{
		if (data->c.b_freq < 0.56)
			data->c.b_freq += 0.11;
		else
			data->c.b_freq = 0;
	}
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		ft_mmove(data, x, y, 0.3);
		data->zoom *= 1.1;
		ft_draw_fractal(data);
	}
	if (button == 5)
	{
		ft_mmove(data, x, y, 0.3);
		data->zoom /= 1.1;
		if (data->zoom < 0.3)
			data->zoom = 0.3;
		ft_draw_fractal(data);
	}
	return (0);
}

int	ft_loop_hook(t_data *img)
{
	mlx_do_sync(img->mlx);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}
