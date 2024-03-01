#pragma once
#include "graphx.h"
#include "gfx/gfx.h"
#include <stdlib.h>
#define M_SPRITE gfx_sprite_t *
#define M_GRAPHICS_BUFFER gfx_location_t

struct Sprite{
    float x, y;
    M_SPRITE contents;
};
// this makes it so you can use "Sprite" like a regular type
typedef struct Sprite Sprite;

// input: gfx image
// TODO: partial redraw
Sprite* m_CreateSprite(M_SPRITE image, float x, float y){
    Sprite* n_sprite = malloc(sizeof(Sprite));
    if (n_sprite == NULL){
        return NULL;
    }
    n_sprite->x = x;
    n_sprite->y = y;
    n_sprite->contents = image;
    return n_sprite;
}

void m_DestroySprite(Sprite* sprite){
    free(sprite);
}

/*WARNING: Call this function before any other graphics-
initializes everything
TODO: make configurable*/
void m_StartRender(){
    gfx_Begin();
    // set palette for sprites
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(0);
    // draw to the onscreen buffer
    gfx_SetDrawBuffer();
}

// must be called at the end of the program, or it messes up the os
#define m_EndRender gfx_End

void m_DrawStaticSprite(Sprite* sprite){
    gfx_Sprite_NoClip(sprite->contents, sprite->x, sprite->y);
}

void m_DrawTransparentSprite(Sprite* sprite){
    gfx_TransparentSprite(sprite->contents, sprite->x, sprite->y);
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