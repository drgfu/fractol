/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:36:34 by tjairus           #+#    #+#             */
/*   Updated: 2022/03/28 09:18:32 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <unistd.h>
# include <math.h>

typedef struct s_numbr {
	double	real;
	double	img;
}			t_numbr;

typedef struct s_color
{
	int			cent;
	int			wid;
	float		r_freq;
	float		g_freq;
	float		b_freq;
	float		r_phase;
	float		g_phase;
	float		b_phase;
	float		color_index;
	int			palette;
	int			is_rainbow;
}				t_color;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		type;
	int		x;
	int		y;
	int		i;
	double	minreal;
	double	maxreal;
	double	minimg;
	double	maximg;
	double	juliareal;
	double	juliaimg;
	double	zoom;
	double	movex;
	double	movey;
	t_color	c;
}				t_data;

void	ft_draw_pixel(t_data *data, int x, int y, int color);
int		mandelbrot(t_data *data);
int		ship(t_data *data);
int		julia(t_data *data);
double	ft_getreal(int x, t_data *f);
double	ft_getimg(int y, t_data *f);
int		get_color(t_data *m, int i, t_numbr new);
int		get_color2(t_data *m, int i, t_numbr new);
void	ft_zoom(t_data *data, double faktor);
void	ft_mmove(t_data *data, int mousex, int mousey, double faktor);
void	ft_draw_fractal(t_data *data);
int		ft_mouse_hook(int button, int x, int y, t_data *data);
int		ft_key_hook(int code, t_data *data);
int		ft_key_hook_color(int code, t_data *data);
int		ft_rgb_switch_hook(int code, t_data *data);
int		ft_loop_hook(t_data *img);
void	ft_init_window(t_data *data, int x, int y, int i);
t_data	*ft_blank(t_data *data);
void	init_burningship(t_data *data);
void	init_julia(t_data *data);
void	init_mandelbrot(t_data *data);
void	setup_color(t_data *data);
int		the_end(t_data *data);

#endif