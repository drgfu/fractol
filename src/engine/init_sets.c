/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:31:00 by tjairus           #+#    #+#             */
/*   Updated: 2022/03/27 23:58:22 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	ft_init_window(t_data *data, int x, int y, int i)
{
	data->x = x;
	data->y = y;
	data->i = i;
	data->movex = 0;
	data->movey = 0;
	if (data->type == 1)
		init_mandelbrot(data);
	else if (data->type == 2)
		init_julia(data);
	else if (data->type == 3)
		init_burningship(data);
}

t_data	*ft_blank(t_data *data)
{
	data = malloc(sizeof(t_data));
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->type = 0;
	data->x = 900;
	data->y = 600;
	data->i = 500;
	data->minreal = .0;
	data->maxreal = .0;
	data->minimg = .0;
	data->maximg = .0;
	data->zoom = 1.0;
	data->movex = .0;
	data->movey = .0;
	return (data);
}

void	init_mandelbrot(t_data *data)
{
	data->maxreal = 1.0;
	data->minreal = -2.0;
	data->maximg = 1.0;
	data->minimg = -1.0;
	data->zoom = 1.0;
}

void	init_julia(t_data *data)
{
	data->maxreal = 3.0;
	data->minreal = -3.0;
	data->maximg = 2.0;
	data->minimg = -2.0;
	data->zoom = 1.2;
}

void	init_burningship(t_data *data)
{
	data->maxreal = 2.6;
	data->minreal = -2.2;
	data->maximg = 1.8;
	data->minimg = -1.8;
	data->zoom = 0.8;
}
