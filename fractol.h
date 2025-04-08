/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:31:30 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/05 13:35:56 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libftx/libft.h"
# include "mlx_linux/mlx.h"

# define TRUE 1
# define FALSE 0
# define MANDELBROT_ID 1
# define JULIA_ID 2
# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define X_MIN -2.0
# define X_MAX 1.0
# define Y_MIN -1.5
# define Y_MAX 1.5

typedef struct s_complex
{
	double		real_x;
	double		imaginary_y;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
}				t_mlx;

typedef struct s_utils
{
	double		x;
	double		y;
	int			iter;
	double		xtemp;
}				t_utils;

typedef struct s_set_call
{
	t_mlx		*screen;
	t_complex	*c;
	t_complex	*z;
	double		zoom;
	int			mandelbrot;
	int			color_factor;
}				t_set_call;

int				main(int argc, char *argv[]);
int				init_param(t_set_call *param, t_mlx *screen);
int				close_window(t_set_call *param);
int				change_color(int *color_factor);
int				key_move(int keycode, t_set_call *param);
int				handle_keys(int keycode, t_set_call *param);
int				zoom(int type, int x, int y, t_set_call *param);
void			julia_formula(t_complex *z, t_complex *c, t_utils *misc_utils);
int				color_seed(void);
int				get_color(int iter, int color_factor);
void			*init_screen_mlx(t_mlx *t_mlx, char **argv);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				is_sets_available(char **argv, int argc, t_set_call *param,
					t_mlx *screen);
int				error_msg(int error_code);
int				error_msg_malloc(int error_code);
int				error_msg_help(void);
int				free_all(t_mlx *screen, t_set_call *param, int error_code);
void			pixel_coordinates(t_complex *center, t_utils *pixel,
					t_complex *out, double zoom);
void			initialize_complex(t_set_call *param, t_complex *z,
					t_complex *c, t_utils *misc_utils);
int				set(t_set_call *param);
double			ft_atop(const char *nptr, t_set_call *param, t_mlx *screen);
double			convert_ascii_to_double(int i, const char *nptr, int negative,
					double result);
#endif