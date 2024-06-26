#include <stdio.h>
#include "LIN.h"
#include <lin_hw.h>
#include "lin_master.h"

int LIN_enuInit(void)
{
    lin_hw_enuInit();
    // MMS: Master Only for now
    lin_master_enuInit();
    return 0;
}

void LIN_enuMainFunction(void)
{

    return;
}
