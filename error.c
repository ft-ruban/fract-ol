#include "fractol.h"
#include <string.h> //TORM BFR PUSH

//Free_null function because it is more readable that way.
//status : COMPLETE 100%
void *free_null(void *target)
{
    free(target);
    target = NULL;
    return(target);
}
//Error messages that function will print a predefined error message to warn the user
//status : WIP 10%
//TODO : ft_printfd to send error to the error fd related + different error messages depending of the returned code!
int error_msg(int error_code)
{
    ft_printf("Error"); //put fd 2
    return (1);
}

//will determine which fractal was selected set set_num with the right numbercode verify if the number of arguments are valids and setup what need to be
//set up at the start (like the x-y value of Julia fractal that was given by the user at launch) if error return 1 that will then lead to Error msg.
//status : WIP 90% 
//TODO : send different return value depending of the error type (to send differents error messages depending of the situation)

int is_sets_available(char **argv, int *set_num, int argc, t_complex *c)
{
    if (argc == 1)
        return (1);
    else if (!ft_strcmp (argv[1], "Mandelbrot"))
    {    
        if (argc != 2)
            return (2);
        *set_num = 1;
        return (0);
    }
    else if (!ft_strcmp (argv[1], "Julia"))
    {    
        if (argc != 4)
            return (3);
        c->real_x = ft_atop(argv[2]);
        c->imaginary_y = ft_atop(argv[3]);
        *set_num = 2;        
        return (0);
    }
    else if (!ft_strcmp (argv[1], "Help"))
    {
        ft_printf("topmoumoute");
        return (4);
    }
    else
        return (5);
}
