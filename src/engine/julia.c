/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:31:10 by tjairus           #+#    #+#             */
/*   Updated: 2022/03/28 00:33:15 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static void	ft_julia_iterate(t_data *data, int x, int y)
{
	t_numbr	old;
	t_numbr	new;
	t_numbr	poi;
	int		i;

	i = 0;
	new.real = ft_getreal(x, data);
	new.img = ft_getimg(y, data);
	poi.real = data->juliareal;
	poi.img = data->juliaimg;
	while (i < data->i)
	{
		old.real = new.real;
		old.img = new.img;
		new.real = old.real * old.real - old.img * old.img + poi.real;
		new.img = 2 * old.real * old.img + poi.img;
		if (new.real * new.real + new.img * new.img > 4)
			break ;
		i++;
	}
	ft_draw_pixel(data, x, y, get_color(data, i, new));
}

int	julia(t_data *data)
{
	int	x;
	int	y;	

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			ft_julia_iterate(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
