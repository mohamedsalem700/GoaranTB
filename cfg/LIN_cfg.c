
#include "LIN_cfg.h"

LIN_tstrMaster_frame LIN_strMaster_frame_table[LIN_Master_Table_Size] = {
    {

        .offset_ms = 10,
        .response_wait_ms = 1,
        .slot = {0x23, LIN_FRAME_TYPE_Tx, 8, NULL}

    },
    {

        .offset_ms = 25,
        .response_wait_ms = 25,
        .slot = {0x22, LIN_FRAME_TYPE_Rx, 8, NULL}

    }

};

LIN_tstrLDFConfig LIN_strLDFConfig = {
    .LIN_strMaster_frame_table = LIN_strMaster_frame_table,
    .LIN_u8Master_frame_table_size = LIN_Master_Table_Size,
};