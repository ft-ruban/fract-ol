#include "fractol.h"
#include <string.h> //TORM BFR PUSH
int free_wip(void)
{
    return 0;
}
int error_msg()
{
    //TODO error msg
    return (1);
}
int is_sets_available(char *argv)
{
    if (strcmp (argv, "Mandelbrot")) //TODO libft + all the sets available
        return (1);
    else
        return (0);
}