#include "fractol.h"

void	mandelbrot_set(t_mlx *mlx, t_complex *c)
{
	int			x;
	int			y;
	int			iter;
	t_complex	z;
	double		xtemp;

	y = 0;
	while (y < WIN_WIDTH)
	{
		x = 0;
		while (x < WIN_HEIGHT)
		{
			c->real_x = (x - WIN_HEIGHT_HALF) * 4.0 / WIN_HEIGHT;
			// zoom = 4.0 TODO create variable zoom
			c->imaginary_y = (y - WIN_WIDTH_HALF) * 4.0 / WIN_HEIGHT; //offset
			// zoom = 4.0
			z.real_x = 0;
			z.imaginary_y = 0;
			iter = 0;
			while (z.real_x * z.real_x + z.imaginary_y * z.imaginary_y <= 4
				&& iter < 256)
			{
				xtemp = z.real_x * z.real_x - z.imaginary_y * z.imaginary_y
					+ c->real_x;
				z.imaginary_y = 2 * z.real_x * z.imaginary_y + c->imaginary_y;
				z.real_x = xtemp;
				iter++;
			}
			my_mlx_pixel_put(&(mlx->img), x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
}
