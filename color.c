#include "fractol.h"

/*int get_color(int iter)
{
    if (iter == 256)
        return 0x000000; //black for the inside
    return 0xFF0000 + (iter << 8); // shades of red
}*/ 
int get_color(int iter)
{
    int red = (iter * 9) % 256;
    int green = (iter * 2) % 256;
    int blue = (iter * 5) % 256;
    return (red << 16) | (green << 8) | blue;
}
