#pragma once
#include "graphx.h"
#include "gfx/gfx.h"
#include <stdlib.h>
#define M_SPRITE gfx_sprite_t *
#define M_GRAPHICS_BUFFER gfx_location_t

struct Sprite{
    float x, y;
    M_SPRITE contents;
    bool isDynamic;
    M_SPRITE background;
};
// this makes it so you can use "Sprite" like a regular type
typedef struct Sprite Sprite;

// input: gfx image, whether or not to treat it with partial redraw
// height, width of sprite
Sprite* m_CreateSprite(M_SPRITE image, float x, float y, bool isDynamic, int height, int width){
    Sprite* n_sprite = malloc(sizeof(Sprite));
    if (n_sprite == NULL){
        return NULL;
    }
    n_sprite->x = x;
    n_sprite->y = y;
    n_sprite->contents = image;
    n_sprite->isDynamic = isDynamic;
    if(isDynamic){
        M_SPRITE background = NULL;
        background = gfx_MallocSprite(width,height);
        if(background == NULL){
            return NULL;
        }
        n_sprite->background = background;
    }
    else{
        n_sprite->background == NULL;
    }
    // WARNING: MAY BE BUG HERE
    gfx_GetSprite(n_sprite->background, n_sprite->x, n_sprite->y);
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

// m_MoveSprite:
// Takes in sprite to move, x+y to move to

void m_MoveSprite(Sprite* sprite, int x, int y){
    if(!sprite->isDynamic){return;}
    gfx_Sprite(sprite->background, sprite->x, sprite->y);
    sprite->x = x;
    sprite->y = y;
    gfx_GetSprite(sprite->background, sprite->x, sprite->y);
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