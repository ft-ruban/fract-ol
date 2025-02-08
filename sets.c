#include "fractol.h"

void mandelbrot_set(t_mlx *t_mlx)
{
    int x;
    int y;
    int z;
    int i;

    x = 960;
    y = 540;
    z = 100;
    i = 0;
    while(i != 0)
    {
        //fonction coordo f
        my_mlx_pixel_put(&(t_mlx->img), x, y, 0xFF0000);
        x += 1;
        y += 5;
        z--;
    }
    // my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);

	mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_mlx->img.img, 0, 0);
	 mlx_loop(t_mlx ->mlx);
}