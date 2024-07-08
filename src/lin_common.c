/*!
 * @brief Initialize the controller specified by name, i.e. sets up internal
 *  functions such as the baud rate. The default schedule set by the l_ifc_init
 *  call will be the L_NULL_SCHEDULE where no frames will be sent and received.
 *  This is the first call a user must perform, before using any other interface
 *  related LIN API functions.
 */
l_bool l_ifc_init(l_ifc_handle iii)
{
    l_bool bFuncStatusLoc = lin_ok;
    /* init lin Hardware */
    /* lin header */
    /*
    1.  calculate header Timeout
    2. save header time out

    */
    bFuncStatusLoc = lin_hw_enuInit();
    if (bFuncStatusLoc)
    {
        /**
         * 1. get the defaule schedule table
         * 2. init Tranmission and reception flags
         *
         */
    }

    return (bFuncStatusLoc);
}

/*!
 *  Description Set up the next schedule table
 */
void l_sch_set(l_ifc_handle iii,
               l_schedule_handle schedule_iii,
               l_u8 entry)
{

        
}



/*!
 * Description This function perform the lin schedular in LDF

 */
l_u8 l_sch_tick(l_ifc_handle iii)
{
    l_bool bFuncStatusLoc = lin_ok;

    /**
     * 1. get the active schedule table
     * 2. check diagnostic interleaved
     * 3. check if time of next transmittion 
     *  i. Update tranmission time for next time. 
     *  ii. get frame index to send
     *  iii. send header.
     *  iv. update next entery.(rollover/switch if needed)
     * 4. update scheduler tick.
     * 5. update the status words 
     * 
     **/

    return (bFuncStatusLoc);
}
