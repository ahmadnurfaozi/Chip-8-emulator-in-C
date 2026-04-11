#include "chip8screen.h"
#include <assert.h>

static void is_screen_check_bound(int x, int y){
    assert(x >= 0 && x < CHIP8_HEIGHT && y >= 0 && y < CHIP8_WIDTH);
}

void chip8_screen_set(struct chip8_screen *screen, int x, int y){
    is_screen_check_bound(x, y);
    screen->pixels[x][y] = true;
}

bool chip8_screen_is_set(struct chip8_screen *screen, int x, int y){
    is_screen_check_bound(x, y);
    return screen->pixels[x][y];
}