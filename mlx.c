#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + (y * data->line_length + x
				* (data->bits_per_pixel >> 3))) = color;
}

void	init_screen_mlx(t_mlx *t_mlx)
{
	t_complex *c;

	c = malloc(sizeof(t_complex));
	t_mlx->mlx = mlx_init();
	t_mlx->mlx_win = mlx_new_window(t_mlx->mlx, WIN_HEIGHT, WIN_WIDTH,
			"proutzor"); //  make a window called hello world! of res 1920,
						//1080 with the pointer mlx
	t_mlx->img.img = mlx_new_image(t_mlx->mlx, WIN_HEIGHT, WIN_WIDTH);
	t_mlx->img.addr = mlx_get_data_addr(t_mlx->img.img,
			&(t_mlx->img.bits_per_pixel), &(t_mlx->img.line_length),
			&(t_mlx->img.endian));
	mandelbrot_set(t_mlx, c);
}
