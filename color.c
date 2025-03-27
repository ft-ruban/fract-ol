#include "fractol.h"

//Would determine how to color the pixel depending of the iteration, if the max iteration (256)
//is reached it mean we are in the black reach
//if we are below we will get a rgb code to color depending of the reach!
//NOTE: changing the max iter obviously change the colors of the fractal
//status : COMPLETED
//TODOIFBONUS : maybe add a keyboard command to change color without changing the iter?
// int get_color(int iter)
// {
//     if (iter == 256)
//         return 0x000000;

//     int red = (iter * 9) % 256; //Alex add +x to change
//     int green = (iter * 2) % 256;
//     int blue = (iter * 5) % 256;
//     return (red << 16) | (green << 8) | blue;
// }

int color_seed() {
    unsigned long seed;
    void *ptr;
    
    ptr = malloc(1);
    if (!ptr) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    seed = (unsigned long)ptr;
    free(ptr);
    return seed % (1L << 16);
}

int get_color(int iter, int color_factor) {
    if (iter == 256) return 0x000000;

    unsigned char red = (iter * (color_factor & 0xF)) % 256; 
    unsigned char green = (iter * ((color_factor >> 4) & 0xF)) % 256;
    unsigned char blue = (iter * ((color_factor >> 8) & 0xF)) % 256;

    return (red << 16) | (green << 8) | blue;
}