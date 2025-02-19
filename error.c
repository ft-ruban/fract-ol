#include "fractol.h"
#include <string.h> //TORM BFR PUSH
void *free_null(void *target)
{
    free(target);
    target = NULL;
    return(target);
}
int error_msg()
{
    printf("Error"); //put fd 2
    return (1);
}
//if mandel set_num == 1
int is_sets_available(char *argv, int *set_num)
{
    if (!strcmp (argv, "Mandelbrot")) //TODO libft + all the sets available
    {    
        *set_num = 1;        
        return (0);
    }
    /*
    else if (!strcmp (argv, "Julia")) //TODO libft + all the sets available
    {    
        *set_num = 2;        
        return (0);
    }*/
    else
        return (1);
}