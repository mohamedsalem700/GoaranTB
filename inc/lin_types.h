#pragma once

#include "TYP.h"

typedef enum lin_enuframe_type
{
    LIN_FRAME_TYPE_Tx,
    LIN_FRAME_TYPE_Rx
} lin_tenuFrame_type;

typedef struct open_lin_frame
{
    u8 pid;
    lin_tenuFrame_type frame_type;
    u8 data_length;
    u8 *data_ptr;
} lin_tstrFrame;

typedef struct LIN_strmaster_frame_table
{
    u8 offset_ms;
    u8 response_wait_ms;
    lin_tstrFrame slot;
} LIN_tstrMaster_frame_table;

typedef struct LIN_strLDFConfig
{

    LIN_tstrMaster_frame_table *LIN_strMaster_frame_table;
    u8 LIN_u8Master_frame_table_size;
} LIN_tstrLDFConfig;
