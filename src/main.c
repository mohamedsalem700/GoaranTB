// C library headers
#include <stdio.h>
#include <string.h>

#include "LIN.h"
extern int serial_port;
int main(void)
{
    LIN_enuInit();

    return 0; // success
}