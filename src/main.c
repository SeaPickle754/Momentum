#include "momentum/graphics.h"
#include "momentum/input.h"
#include "momentum/textControl.h"


#include "gfx/gfx.h"

// include the sprites

/* Main function, called first */
int main(void)
{
    m_StartRender();
    Sprite* oiram_sprite = m_CreateSprite(oiram, 100, 100, true, 27, 16);
    if (oiram_sprite == NULL){
        m_EndRender();
        m_PrintStr("ERROR: No memory left for image!");
        return 1;
    }

    m_DrawTransparentSprite(oiram_sprite);

    m_FlipBuffer(M_DEFAULT_FRAMEBUFFER);


    while(true){

        int x, y;
        x = oiram_sprite->x;
        y = oiram_sprite->y;
        kb_key_t arrows;
        if(kb_On){
            break;
        }
        /* Scan the keypad to update kb_Data */
        kb_Scan();

        /* Get the arrow key statuses */
        arrows = kb_Data[7];

        /* Check if any arrows are pressed */
        if (arrows)
        {
            /* Do different directions depending on the keypress */
            if (arrows & kb_Right)
            {
                x += 2;
            }
            if (arrows & kb_Left)
            {
                x -= 2;
            }
            if (arrows & kb_Down)
            {
                y += 2;
            }
            if (arrows & kb_Up)
            {
                y -= 2;
            }
        
        m_MoveSprite(oiram_sprite, x, y);
        m_DrawTransparentSprite(oiram_sprite);
        m_FlipBuffer(M_DEFAULT_FRAMEBUFFER);
        }
        
    }
    m_EndRender();
    m_DestroySprite(oiram_sprite);
    return 0;
}
