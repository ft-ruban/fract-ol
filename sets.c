#include "fractol.h"

void	mandelbrot_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z)
{
	while (misc_utils->y < WIN_HEIGHT)
	{
		misc_utils->x = 0;
		while (misc_utils->x < WIN_WIDTH) //TODO maybe calculate only what I need depending of the zoom?
		{
			c->real_x = (misc_utils->x - WIN_WIDTH_HALF) * 4.0 / WIN_WIDTH;
			// zoom = 4.0 TODO create variable zoom
			c->imaginary_y = (misc_utils->y - WIN_HEIGHT_HALF) * 4.0 / WIN_WIDTH; //offset
			// zoom = 4.0 mult and div x/y - winhalf would move the plan
			z->real_x = 0;
			z->imaginary_y = 0;
			misc_utils->iter = 0;
			while (z->real_x * z->real_x + z->imaginary_y * z->imaginary_y <= 4
				&& misc_utils->iter < 256)
			{
				misc_utils->xtemp = z->real_x * z->real_x - z->imaginary_y * z->imaginary_y
					+ c->real_x;
				z->imaginary_y = 2 * z->real_x * z->imaginary_y + c->imaginary_y;
				z->real_x = misc_utils->xtemp;
				misc_utils->iter += 1;
			}
			my_mlx_pixel_put(&(mlx->img), misc_utils->x, misc_utils->y, get_color(misc_utils->iter));
			misc_utils->x += 1;
		}
		misc_utils->y += 1;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
}
//25 lines if I remove coms!!!
/*void	julia_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z)
{
	//TODO
}
*/

void sets(int set_num, t_mlx *mlx)
{
	t_complex	c;
	t_complex	z;
	t_utils misc_utils;

	//TODO utils would contain the zoom ratio?
	misc_utils.y = 0;
	//TODO? add more variables to win some spaces!!!
	if(set_num == 1)
		mandelbrot_set(mlx, &c, &misc_utils, &z);

	//if(set_num == 2)
		//julia_set(mlx, &c, &misc_utils,&z);
		//TODO Julia set
	return;
}
