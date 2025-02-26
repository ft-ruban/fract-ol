#include "fractol.h"
#include <string.h> //TORM BFR PUSH

//Free_null function because it is more readable this way + we save a lot of lines
//limits
//status : COMPLETE
void *free_null(void *target)
{
    free(target);
    target = NULL;
    return(target);
}
//Error messages that function will print a predefined error message to warn the user
//status : WIP
int error_msg()
{
    ft_printf("Error"); //put fd 2
    return (1);
}
//if mandel set_num == 1
int is_sets_available(char **argv, int *set_num, int argc, t_complex *c)
{
    printf("string : %s\n",argv[2]);
    if (!strcmp (argv[1], "Mandelbrot")) //TODO libft + all the sets available
    {    
        if (argc != 2)
            return (1);
        *set_num = 1;        
        return (0);
    }
    
    else if (!strcmp (argv[1], "Julia")) //TODO libft + all the sets available
    {    
        if (argc != 4)
            return (1);
        c->real_x = (long double)-0.202420806884766;//ft_atop(argv[2]); //-0.7
        c->imaginary_y = (long double)0.39527333577474;//ft_atop(argv[3]); //0.27015
        printf("value of realx = %.15f \n /*value of imaginary_y = %.15f \n*/",c->real_x,c->imaginary_y);
        *set_num = 2;        
        return (0);
    }
    else
        return (1);
}