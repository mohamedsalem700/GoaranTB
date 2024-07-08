#pragma once 


#include "lin.h"



/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * Description:  This function performs the initialization of the LIN core
 */
l_bool l_sys_init(void);



/*!
 * Description This function perform the lin schedular in LDF

 */
l_u8 l_sch_tick(l_ifc_handle iii);

/*!
 *  Description Set up the next schedule table 
 */
void l_sch_set(l_ifc_handle iii,
               l_schedule_handle schedule_iii,
               l_u8 entry);



/*!
 * @brief Initialize the controller specified by name, i.e. sets up internal
 *  functions such as the baud rate. The default schedule set by the l_ifc_init
 *  call will be the L_NULL_SCHEDULE where no frames will be sent and received.
 *  This is the first call a user must perform, before using any other interface
 *  related LIN API functions.
 */
l_bool l_ifc_init(l_ifc_handle iii);

/*!
 * Description Request slave nodes on the cluster connected to the interface to enter
 *  bus sleep mode by issuing one go to sleep command.
 *  This API is available only for Master nodes.
 */
void l_ifc_goto_sleep(l_ifc_handle iii);


/*!
 * Description  Transmit the wake up signal.
 */
void l_ifc_wake_up(l_ifc_handle iii);

/*!
 * Description This function will return the status of the previous communication.
 */
l_u16 l_ifc_read_status(l_ifc_handle iii);


/*!
 *  Description Disable LIN INTP
 */
l_u16 l_sys_irq_disable(l_ifc_handle iii);

/*!
 * Description Enable LIN INTP.

 */
void l_sys_irq_restore(l_ifc_handle iii);




/******************************************************************************/
/* EOF */
/******************************************************************************/
