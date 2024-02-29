#include <ti/screen.h>
#include <ti/getcsc.h>

void m_ClearHome(){
    os_ClrHome();
}

void m_PrintStr(char* text){
    os_PutStrFull(text);
}