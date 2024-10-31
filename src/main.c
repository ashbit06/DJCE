#include <graphx.h>
#include <gfx/gfx.h>
#include <keypadc.h>
#include <fileioc.h>
#include <tice.h>
#include <ti/getcsc.h>
#include <debug.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define SCROLL_TRIGGER     30
#define GRAVITY            -0.64
#define FRICTION           0.64
#define JUMP               -8
#define SPEED              0.68
#define TRANSPARENT_COLOR  1

/*
  1: move direction
  2: shoot direction
*/
struct Player {
    float x;
    float y;
    float dx;
    float dy;
    bool canMove;
    int shootDir;
};

struct Platform {
    float mapX;
    float mapY;
    int type;
};

void drawPlayer(struct Player p) {
    gfx_Sprite_NoClip(doodle0, p.x, p.y);
    gfx_TransparentSprite_NoClip(doodle0, p.x, p.y+60);
}

void handlePlayerMovement(struct Player *p) {
    if (kb_IsDown(kb_KeyRight)) p->x += 5;
    else if (kb_IsDown(kb_KeyLeft)) p->x -= 5;
}

int main() {
    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(0x01);

    srand(rtc_Time());

    int scrollY = 0;
    bool isPaused = false;

    struct Player player;
    player.x = 0;
    player.y = 0;
    player.canMove = true;

    // main game loop
    while (1) {
        kb_Scan();
        if (kb_Data[6] & kb_Clear) {
            break;
        }

        gfx_FillScreen(1);
        gfx_SetColor(0x00);
        gfx_FillRectangle((int)(GFX_LCD_WIDTH/2), 0, 30, 240);

        if (!isPaused) handlePlayerMovement(&player);
        drawPlayer(player);

        // main game logic

        gfx_SwapDraw();
        delay(50);
    }

    gfx_End();
    return 0;
}