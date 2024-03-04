#include <keypadc.h>

#define KEYEVENT kb_key_t

void m_ScanKeypresses(){
    kb_Scan();
}

KEYEVENT m_GetNewestKeypress(){
    return kb_Data[0];
}