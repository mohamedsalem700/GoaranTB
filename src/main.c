#include <stdio.h>
#include "LIN.h"
#include "UART.h"

void main(void)
{
    printf("==>INIT\n");
    UART_vidInit();
    printf("==>write\n");
    for (int i = 0; i < 10000; i++)
    {
        UART_vidWrie("Hello", 5);
    }
    printf("==>EXIT\n");

    //   close(serial_port);
}
