#pragma once
#include "graphx.h"

#define M_SPRITE gfx_sprite_t
#define M_GRAPHICS_BUFFER gfx_location_t
#define M_PALETTE unsigned char*

/*WARNING: Call this function before any other graphics-
initializes everything
TODO: make configurable*/
void m_StartRender(M_PALETTE global_palette){
    gfx_Begin();
    // set palette for sprites
    gfx_SetPalette(global_palette, sizeof(global_palette), 0);
    gfx_SetTransparentColor(0);
    // draw to the onscreen buffer
    gfx_SetDrawBuffer();
}

// must be called at the end of the program, or it messes up the os
#define m_EndRender gfx_End

void m_DrawStaticSprite(M_SPRITE* sprite, int x, int y){
    gfx_Sprite_NoClip(sprite, x, y);
}

void m_DrawDynamicSprite(M_SPRITE* sprite, int x, int y){
    gfx_TransparentSprite(sprite, x, y);
}

/*Draws the current buffer to the screen
Arguments:
*Optional: "buffer" - the buffer to flip, if null is provided gfx_buffer*/
void m_FlipBuffer(M_GRAPHICS_BUFFER buffer){
    if (buffer == NULL){   
        gfx_BlitBuffer();
    }
    else{
        gfx_Blit(buffer);
    }
}