#include "fractol.h"

void	mandelbrot_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z)
{
	while (misc_utils->y < WIN_HEIGHT) //1080
	{
		misc_utils->x = 0;
		while (misc_utils->x < WIN_WIDTH) //TODO maybe calculate only what I need depending of the zoom?
		{
			c->real_x = (misc_utils->x - WIN_WIDTH_HALF + 0) * 4.0 / WIN_WIDTH;
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
	if(set_num == 1) //TODO enum
		mandelbrot_set(mlx, &c, &misc_utils, &z);

	//if(set_num == 2)
		//julia_set(mlx, &c, &misc_utils,&z);
		//TODO Julia set
	return;
}
