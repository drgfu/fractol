/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:29:58 by tjairus           #+#    #+#             */
/*   Updated: 2022/03/28 00:33:35 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static void	ft_iterate_ship(t_data *data, int x, int y)
{
	t_numbr	old;
	t_numbr	new;
	t_numbr	poi;
	int		i;

	i = 0;
	new.real = 0;
	new.img = 0;
	poi.real = ft_getreal(x, data);
	poi.img = ft_getimg(y, data);
	while (i < data->i)
	{
		old.real = new.real;
		old.img = new.img;
		new.real = old.real * old.real - old.img * old.img - poi.real;
		new.img = 2 * fabs(old.real * old.img) - poi.img;
		if (new.real * new.real + new.img * new.img > 4)
			break ;
		i++;
	}
	ft_draw_pixel(data, x, y, get_color(data, i, new));
}

int	ship(t_data *data)
{
	int	x;
	int	y;	

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			ft_iterate_ship(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
