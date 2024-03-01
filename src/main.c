#include "momentum/graphics.h"
#include "momentum/input.h"
#include "momentum/textControl.h"


#include "gfx/gfx.h"

// include the sprites

/* Main function, called first */
int main(void)
{
    m_StartRender(global_palette);
    Sprite* oiram_sprite = m_CreateSprite(oiram, 100, 100);
    if (oiram_sprite == NULL){
        m_EndRender();
        m_PrintStr("ERROR: No memory left for image!");
        return 1;
    }
    m_DrawTransparentSprite(oiram_sprite);

    m_FlipBuffer(NULL);

    while(m_GetNewestKeypress()!=kb_Clear);
    m_EndRender();
    m_DestroySprite(oiram_sprite);
    return 0;
}
