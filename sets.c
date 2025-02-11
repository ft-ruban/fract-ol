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
t_complex   ft_complex_mul(t_complex first, t_complex second);
void	mandelbrot_set(t_mlx *mlx, t_complex c)
{
	int			x;
	int			y;
	int			iter;
	t_complex	z;
    double xtemp;

	y = 0;
	while (y < WIN_WITH)
	{
		x = 0;
		while (x < WIN_HEIGH)
        {
            c.real_x = (x - WIN_HEIGH / 2.0) * 4.0 / WIN_HEIGH;
            c.imaginary_y = (y - WIN_WITH / 2.0) * 4.0 / WIN_HEIGH;
            z.real_x = 0;
            z.imaginary_y = 0;
            iter = 0;
            while (z.real_x * z.real_x + z.imaginary_y * z.imaginary_y <= 4
                && iter < 256)
            {
                xtemp = z.real_x * z.real_x - z.imaginary_y * z.imaginary_y
                    + c.real_x;
                z.imaginary_y = 2 * z.real_x * z.imaginary_y + c.imaginary_y;
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
t_complex	ft_complex_add(t_complex first, t_complex second)
{
	t_complex result;
	result.real_x = first.real_x + second.real_x;
	result.imaginary_y = first.imaginary_y + second.imaginary_y;
    return (result);
}
t_complex 	ft_complex_mul(t_complex first, t_complex second)
{
    t_complex result;

    result.real_x = first.real_x * second.real_x - first.imaginary_y * second.imaginary_y;
    result.imaginary_y = first.real_x * second.imaginary_y + first.imaginary_y * second.real_x;
    return (result);
}
