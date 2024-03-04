#include <keypadc.h>

#define KEYEVENT kb_key_t

void m_ScanKeypresses(){
    kb_Scan();
}
// read documentation on https://ce-programming.github.io/toolchain/libraries/keypadc.html
// for the table of groups
KEYEVENT* m_GetNewestKeypress(){
    return kb_Data;
}