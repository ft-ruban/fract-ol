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
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_mlx(t_mlx *t_mlx)
{
	//void	*mlx;
	//void	*mlx_win;
	//t_data	img;

	t_mlx->mlx = mlx_init();
	t_mlx->mlx_win = mlx_new_window(t_mlx->mlx, 1920, 1080, "Hello world!"); // we make a window called hello world! of res 1920, 1080 with the pointer mlx
	t_mlx->img.img = mlx_new_image(t_mlx->mlx, 1920, 1080);
	t_mlx->img.addr = mlx_get_data_addr(t_mlx->img.img, &(t_mlx->img.bits_per_pixel), &(t_mlx->img.line_length),
								&(t_mlx->img.endian));
	my_mlx_pixel_put(&(t_mlx->img), 500, 500, 0xFF0000);
	my_mlx_pixel_put(&(t_mlx->img), 500, 501, 0xFF0000);
	my_mlx_pixel_put(&(t_mlx->img), 500, 502, 0xFF0000);
my_mlx_pixel_put(&(t_mlx->img), 501, 500, 0xFF0000);
my_mlx_pixel_put(&(t_mlx->img), 502, 500, 0xFF0000);
my_mlx_pixel_put(&(t_mlx->img), 503, 500, 0xFF0000);
my_mlx_pixel_put(&(t_mlx->img), 501, 501, 0xFF0000);
my_mlx_pixel_put(&(t_mlx->img), 502, 502, 0xFF0000);

	mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_mlx->img.img, 0, 0);
	// mlx_loop(mlx);
}

