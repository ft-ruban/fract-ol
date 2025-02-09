#include "fractol.h"

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
*/
void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
		*(unsigned int *)(data->addr + (y * data->line_length + x
			* (data->bits_per_pixel >> 3))) = color;
}

void	init_screen_mlx(t_mlx *t_mlx)
{
	//void	*mlx;
	//void	*mlx_win;
	//t_data	img;

	t_mlx->mlx = mlx_init();

	t_mlx->mlx_win = mlx_new_window(t_mlx->mlx, WIN_HEIGH, WIN_WITH, "Hello world!"); // we make a window called hello world! of res 1920, 1080 with the pointer mlx
	t_mlx->img.img = mlx_new_image(t_mlx->mlx, WIN_HEIGH, WIN_WITH);
	t_mlx->img.addr = mlx_get_data_addr(t_mlx->img.img, &(t_mlx->img.bits_per_pixel), &(t_mlx->img.line_length),
								&(t_mlx->img.endian));
	mandelbrot_set(t_mlx);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);

	// mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_mlx->img.img, 0, 0);
	// mlx_loop(t_mlx ->mlx);
}

