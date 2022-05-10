/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:19:11 by tjairus           #+#    #+#             */
/*   Updated: 2022/03/28 00:10:30 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

/* calculate the value on the x axis depending on x location
 * on the screen and returns it.  */
double	ft_getreal(int x, t_data *f)
{
	double	max;

	max = fabs(f->maxreal) + fabs(f->minreal);
	max = (double)x * max / ((double)(f->x)) + f->minreal;
	max = max / f->zoom + f->movex;
	return (max);
}

/* calculate the value on the y axis depending on y location
 * on the screen and returns it */
double	ft_getimg(int y, t_data *f)
{
	double	max;

	max = fabs(f->maximg) + fabs(f->minimg);
	max = -1.0 * ((double)(y) *max / ((double)(f->y)) + f->minimg);
	max = max / f->zoom + f->movey;
	return (max);
}

void	ft_zoom(t_data *data, double value)
{
	double	x;
	double	y;

	x = ((fabs(data->minreal) + fabs(data->maxreal)) / (float)(data->x));
	x *= value;
	y = ((fabs(data->minimg) + fabs(data->maximg)) / (float)(data->y));
	y *= value * (float)(data->y) / (float)(data->x);
	data->minreal += x;
	data->maxreal -= x;
	data->minimg += y;
	data->maximg -= y;
}

void	ft_mmove(t_data *data, int mousex, int mousey, double value)
{
	double	x;
	double	y;
	double	centerx;
	double	centery;

	centerx = ft_getreal(data->x / 2, data);
	centery = ft_getimg(data->y / 2, data);
	x = ft_getreal(mousex, data);
	y = ft_getimg(mousey, data);
	data->movex += (x - centerx) * value;
	data->movey += (y - centery) * value;
}

void	ft_draw_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
