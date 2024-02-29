#include "momentum/graphics.h"
#include "momentum/input.h"

#include "gfx/gfx.h"

// include the sprites

/* Main function, called first */
int main(void)
{
    m_StartRender(global_palette);
    m_DrawDynamicSprite(icon, 0, 0);
    m_FlipBuffer(NULL);

    while(m_GetNewestKeypress()!=kb_Clear);
    m_EndRender();
    return 0;
}
