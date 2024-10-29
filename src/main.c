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

int main() {
    gfx_Begin();
    gfx_SetDrawBuffer();
    srand(rtc_Time());

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