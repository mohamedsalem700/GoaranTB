#include "lin_types.h"

#include "LIN_cfg.h"

#include "lin_sch.h"

static u8 u8CurrentDelay;
static u8 u8MasterTableIdx;
static LIN_tstrMaster_frame *pstrMaster_currentFrame;

static void vidMoveToNextFrame(void);
bool bNewFeame = STD_FALSE;
void lin_sch_vidInit(void)
{
    u8MasterTableIdx = 0;
    pstrMaster_currentFrame = &LIN_strLDFConfig.LIN_strMaster_frame_table[u8MasterTableIdx];

    u8CurrentDelay = LIN_strLDFConfig.LIN_strMaster_frame_table->offset_ms - LIN_MAIN_TICK_TIME;
    return;
}

void lin_sch_vidScheduler(void)
{
    if (u8CurrentDelay - LIN_MAIN_TICK_TIME > 0)
    {
        u8CurrentDelay -= LIN_MAIN_TICK_TIME;
    }
    else
    {
        vidMoveToNextFrame();
        bNewFeame = STD_TRUE;
    }
    return;
}
bool lin_sch_bIsNewFrameAvailable(void)
{
    bool bNewFrameLoc = bNewFeame;
    bNewFeame = STD_FALSE;
    return bNewFrameLoc;
}

LIN_tstrMaster_frame *lin_sch_pstrGetCurrentFrame(void)
{
    return pstrMaster_currentFrame;
}
static void vidMoveToNextFrame(void)
{
    if (u8MasterTableIdx < LIN_strLDFConfig.LIN_u8Master_frame_table_size)
    {
        u8MasterTableIdx++;
    }
    else
    {
        u8MasterTableIdx = 0;
    }

    pstrMaster_currentFrame = &LIN_strLDFConfig.LIN_strMaster_frame_table[u8MasterTableIdx];
}