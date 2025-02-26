#include "fractol.h"

//Would determine how to color the pixel depending of the iteration, if the max iteration (256)
//is reached it mean we are in the black reach
//if we are below we will get a rgb code to color depending of the reach!
//NOTE: changing the max iter obviously change the colors of the fractal
//status : COMPLETED
//TODOIFBONUS : maybe add a keyboard command to change color without changing the iter?
int get_color(int iter)
{
    if (iter == 256)
        return 0x000000;

    int red = (iter * 9) % 256; //Alex add +x to change
    int green = (iter * 2) % 256;
    int blue = (iter * 5) % 256;
    return (red << 16) | (green << 8) | blue;
}
