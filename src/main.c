#include <graphx.h>
#include <keypadc.h>
#include <fileioc.h>
#include <tice.h>
#include <debug.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct Player {
    float x;
    float y;
    bool canMove;
};

int main() {
    gfx_Begin();
    gfx_SetDrawBuffer();
    srand(rtc_Time());

    int scrollY = 0;

    struct Player player;
    player.x = 0;
    player.y = 0;
    player.canMove = true;

    // main game loop
    while (1) {
        kb_Scan();
        if (kb_IsDown(kb_Clear)) {
            break;
        }

        gfx_FillScreen(0xff);

        // main game logic

        gfx_SwapDraw();
        delay(50);
    }
}