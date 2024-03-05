#include <keypadc.h>

#define M_KEYEVENT kb_key_t

void m_ScanKeypresses(){
    kb_Scan();
}
// read documentation on https://ce-programming.github.io/toolchain/libraries/keypadc.html
// for the table of groups
M_KEYEVENT* m_GetNewestKeypress(){
    return kb_Data;
}
// arrow keys are all in group 7
M_KEYEVENT m_GetArrowKeyPressed(){
    return kb_Data[7];
}