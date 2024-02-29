#include "momentum/textControl.h"
#include "momentum/input.h"

/* Main function, called first */
int main(void)
{
    
    m_ClearHome();
    m_PrintStr("Hello, World!");
    do{
    if(m_GetNewestKeypress()==kb_2nd){
        m_ClearHome();
        m_PrintStr("TEST");
    }
    } while(m_GetNewestKeypress() != kb_Mode);
    return 0;
}
