#include "fractol.h"
//Function that would handle the clean closure of our program when user
//pressed with their mouse on the window redcross
//status : COMPLETED
int close_window (t_mlx *t_mlx)
{
		printf("Closing\n");
			if(t_mlx->mlx_win)
				mlx_loop_end(t_mlx->mlx);
			if(t_mlx->img.img)
				mlx_destroy_image(t_mlx->mlx, t_mlx->img.img);
			if(t_mlx->mlx_win)
				mlx_destroy_window(t_mlx->mlx, t_mlx->mlx_win);
		if(t_mlx->mlx)	
		{
			mlx_destroy_display(t_mlx->mlx);
			free(t_mlx->mlx);
		}
		exit(0);
}

int key_move(int keycode, t_set_call *param) {
	switch (keycode) {
		case 1:
			param->c->real_x -= param->zoom / 4;
			break;
		case 2:
			param->c->imaginary_y -= param->zoom / 4;
			break;
		case 3:
			param->c->real_x += param->zoom / 4;
			break;
		case 4:
			param->c->imaginary_y += param->zoom / 4;
			break;
		default:
			break;
	}
	return (0);
}

int change_color(int *color_factor) {
	*color_factor = color_seed();
	return (0);
}

int handle_keys(int keycode, t_set_call *param) {
	switch(keycode) {
		case 65307:
			return close_window(param->screen);
			break;
		case 65361:
		case 65362:
		case 65363:
		case 65364:
			return key_move(keycode & 0x7, param);
			break;
		default:
			return change_color(&param->color_factor);
			break;
	}
}

int 	zoom(int type, int x, int y, t_set_call *param)
{
	if (type == 4) {
		param->zoom *= 0.9;
	} else if (type == 5) {
		param->zoom *= 1.1;
	}

	if (param->mandelbrot == TRUE) {
		param->c->real_x += ((double)x - WIN_WIDTH_HALF) / WIN_WIDTH * param->zoom;
		param->c->imaginary_y += ((double)y - WIN_HEIGHT_HALF) / WIN_WIDTH * param->zoom;
	} else {
		param->z->real_x += ((double)x - WIN_WIDTH_HALF) / WIN_WIDTH * param->zoom;
		param->z->imaginary_y += ((double)y - WIN_HEIGHT_HALF) / WIN_WIDTH * param->zoom;
	}

	return (0);
}