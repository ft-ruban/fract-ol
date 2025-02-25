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
    printf("Error"); //put fd 2
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
        c->real_x = -0.7; //atoi(argv[2]); //TODO create an atod
        c->imaginary_y = 0.27015; //atoi(argv[3]);
        *set_num = 2;        
        return (0);
    }
    else
        return (1);
}