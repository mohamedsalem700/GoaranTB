// C library headers
#include <stdio.h>
#include <string.h>

#include "LIN.h"
extern int serial_port;
int main(void)
{

    /* Initialize LIN network interface */
    l_sys_init();
    l_ifc_init(0);
    /* Set Schedule table to Normal */
    l_sch_set(LI0, LI0_NormalTable, 0u);
    

    return 0; // success
}

