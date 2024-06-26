
#include "LIN_cfg.h"

LIN_tstrMaster_frame_table LIN_strMaster_frame_table[LIM_Master_Table_Size] = {
    {

        .offset_ms = 10,
        .response_wait_ms = 1,
        .slot = {0x23, LIN_FRAME_TYPE_Tx, sizeof(master_data_buffer_tx_1), master_data_buffer_tx_1}

    },
    {25, 25, {0x22, LIN_FRAME_TYPE_Rx, sizeof(master_data_buffer_rx_1), master_data_buffer_rx_1}}};

LIN_tstrLDFConfig LIN_strLDFConfig = {
    .LIN_strMaster_frame_table = LIN_strMaster_frame_table,
    .LIN_u8Master_frame_table_size = LIM_Master_Table_Size,
};