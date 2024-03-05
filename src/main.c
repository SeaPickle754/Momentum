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
        M_KEYEVENT* key;
        while(!kb_On){
            m_ScanKeypresses();
            if(m_GetArrowKeyPressed()==kb_Up){
                y+=2;
            }
            else if(m_GetArrowKeyPressed() == kb_Down){
                y-=2;
            }
            else if(m_GetArrowKeyPressed() == kb_Left){
                x-=2;
            }
            else if(m_GetArrowKeyPressed() == kb_Right){
                x+=2;
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
