#include "fractol.h"
//Function that would handle the clean closure of our program when user
//pressed with their mouse on the window redcross
//status : COMPLETED
int cross_window (t_mlx *t_mlx)
{
		printf("Cross activated\n");
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
//Function that would handle the clean closure of our program
//when the user would press the ESC key
//status : COMPLETED
int 	close_window(int keycode, t_mlx *t_mlx)
{
	printf("keycode : %d\n", keycode); //65307 for ESC
	if(keycode == 65307)
	{
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

	return (0);
}