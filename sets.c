#include "fractol.h"

// void mandelbrot_set(t_mlx *t_mlx)
// {
//     double x;
//     double y;
//     double z;
//     int i;

//     x = 0.0;
//     y = 0.0;
//     z = 0.0;
//     i = 0;

//     while(i != 1)
//     {
//         //fonction coordo f
//         my_mlx_pixel_put(&(t_mlx->img), x, y, 0xFF0000);
//         x += 0.0015;
//         printf("test");
//         y += 0.0015;
//         i++;
//     }

//     // my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
// 	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
// 	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
// 	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
// 	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
// 	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
// 	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);
// 	// my_mlx_pixel_put(&(t_mlx->img), 960, 540, 0xFF0000);

// 	mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_mlx->img.img, 0, 0);
// 		mlx_loop(t_mlx ->mlx);
// }

t_complex	ft_complex_add(t_complex first, t_complex second);

void	mandelbrot_set(t_mlx *mlx, t_complex c)
{
	int			x;
	int			y;
	int			i;
	t_complex	z;

	z.real_x = 0;
	z.imaginary_y = 0;
	z.ratio_y = WIN_HEIGH / 2;
	z.ratio_x = WIN_WITH / 2;
	
	y = -1;
	i = 0;
	while (++y < WIN_HEIGH)
	{
		x = -1;
		while (++x < WIN_WITH)
		{
			// EQUATION DE MANDELBROT
			z.imaginary_y = y * z.ratio_y;
			z.real_x = x * z.ratio_x;
			i = 0;
			while (i < 256 && z < 2)
			{
				z = (ft_complex_add(ft_complex_mul(z, z), c));
				i++;
			}
			my_mlx_pixel_put(&(mlx->img), y, x, 0xffff0000 + (i << 8) + i);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	mlx_loop(mlx->mlx);
}

t_complex	ft_complex_add(t_complex first, t_complex second)
{
	t_complex result;
	result.real_x = first.real_x + second.real_x;
	result.imaginary_y = first.imaginary_y + second.imaginary_y;
}
t_complex 	ft_complex_mul(t_complex first, t_complex second)
{
	
}