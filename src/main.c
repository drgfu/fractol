/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:39:25 by tjairus           #+#    #+#             */
/*   Updated: 2022/03/28 09:41:38 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractal.h"

int	the_end(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit (0);
	return (0);
}

static int	ft_print_error(int i, char **argv)
{
	if (i == 1)
	{
		ft_putendl_fd("Please check arguments, choose one of following:", 1);
		ft_putendl_fd("\"./fract-ol burningship\"", 1);
		ft_putendl_fd("\"./fract-ol mandelbrot\"", 1);
		ft_putendl_fd("\"./fract-ol julia\"", 1);
		ft_putendl_fd("-- For julia please add parameters real and img --", 1);
		ft_putendl_fd("-- some ideas what to try are here:", 1);
		ft_putendl_fd("2: ./fract-ol julia 0.285 0.01", 1);
		ft_putendl_fd("3: ./fract-ol julia 0.285 0.02", 1);
		ft_putendl_fd("4: ./fract-ol julia 0.45 0.1428", 1);
		ft_putendl_fd("5: ./fract-ol julia -0.28 -0.5", 1);
		ft_putendl_fd("6: ./fract-ol julia -0.07 0.62", 1);
	}
	else if (i == 2)
	{
		ft_putendl_fd("Please check arguments, for list run ./fract-ol", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putendl_fd(" : is not a valid fractal", 1);
	}
	return (0);
}

static int	check_input2(char **argv, t_data *f)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		f->type = 1;
	else if (!ft_strncmp(argv[1], "julia", 6))
	{
		ft_print_error(1, argv);
		free(f);
		exit(0);
	}
	else if (!ft_strncmp(argv[1], "burningship", 12))
		f->type = 3;
	else
	{
		ft_print_error(2, argv);
		free(f);
		exit(0);
	}
	return (1);
}

static int	check_input(int argc, char **argv, t_data *f)
{
	if (!f || argc < 2 || argc == 3 || argc > 4)
	{
		ft_print_error(1, argv);
		free(f);
		exit(0);
	}	
	else if (argc == 2)
		check_input2(argv, f);
	else if (argc == 4)
	{
		if (!ft_strncmp(argv[1], "julia", 6))
		{
			f->type = 2;
			f->juliareal = ft_atof(argv[2]);
			f->juliaimg = ft_atof(argv[3]);
		}
		else
		{
			ft_print_error(2, argv);
			free(f);
			exit(0);
		}
	}
	ft_init_window(f, 1200, 800, 500);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*img;

	img = ft_blank(NULL);
	if (!check_input(argc, argv, img))
		return (1);
	img->mlx = mlx_init();
	if (!img->mlx)
		return (1);
	img->win = mlx_new_window(img->mlx, img->x, img->y,
			"Fract-ol   			Press Spacebar to see help");
	img->img = mlx_new_image(img->mlx, img->x, img->y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	setup_color(img);
	ft_draw_fractal(img);
	mlx_key_hook(img->win, ft_key_hook, img);
	mlx_hook(img->win, 17, 1L << 2, the_end, img);
	mlx_mouse_hook(img->win, ft_mouse_hook, img);
	mlx_loop_hook(img->mlx, ft_loop_hook, img);
	mlx_loop(img->mlx);
	return (0);
}
