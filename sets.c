#include "fractol.h"

//iterate to each pixels + give the middle point of the screen and redirect to the right formula depending of the asked fractal
//status : WIP 85%
//TODO: Maybe merge all my fractal and just make a condition that would redirect to any formula depending of the user's needs
//TODO: See if there any way to improve the perf of that, I do believe there is some.

void	mandelbrot_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z)
{
	while (misc_utils->y < WIN_HEIGHT) //1080
	{
		misc_utils->x = 0;
		while (misc_utils->x < WIN_WIDTH) //TODO maybe calculate only what I need depending of the zoom?
		{
			c->real_x = (misc_utils->x - WIN_WIDTH_HALF + 0) * 4.0 / WIN_WIDTH; //Alex zoom moyenne entre souris et centre
			c->imaginary_y = (misc_utils->y - WIN_HEIGHT_HALF + 0) * 4.0 / WIN_WIDTH; //offset
			/* zoom = 4.0 mult and div x/y - winhalf would move the plan*/
			mandelbrot_formula(c, z, misc_utils);
			my_mlx_pixel_put(&(mlx->img), misc_utils->x, misc_utils->y, get_color(misc_utils->iter));
			misc_utils->x++;
		}
		misc_utils->y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
}
//refer to comment of mandelbrot_set

void	julia_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z)
{
	while (misc_utils->y < WIN_HEIGHT) //1080
	{
		misc_utils->x = 0;
		while (misc_utils->x < WIN_WIDTH) //TODO maybe calculate only what I need depending of the zoom?
		{
			z->real_x = (misc_utils->x - WIN_WIDTH_HALF + 0) * 4.0 / WIN_WIDTH; //Alex zoom moyenne entre souris et centre
			z->imaginary_y = (misc_utils->y - WIN_HEIGHT_HALF + 0) * 4.0 / WIN_WIDTH; //offset
			/* zoom = 4.0 mult and div x/y - winhalf would move the plan*/
			julia_formula(c, z, misc_utils);
			my_mlx_pixel_put(&(mlx->img), misc_utils->x, misc_utils->y, get_color(misc_utils->iter));
			misc_utils->x++;
		}
		misc_utils->y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
}

//would redirect the program depending of the set_num content that represent which fractal the user is looking for it also init some struct
//that would be used in those said fractal.
//status : WIP 90%
// TODO utils would contain the zoom ratio?
void sets(int set_num, t_mlx *mlx, t_complex *c)
{
	t_complex	z;
	t_utils misc_utils;

	misc_utils.y = 0;
	if(set_num == MANDELBROT_ID)
		mandelbrot_set(mlx, c, &misc_utils, &z);

	if(set_num == JULIA_ID)
	{
		julia_set(mlx, c, &misc_utils,&z);
	}
	return;
}
