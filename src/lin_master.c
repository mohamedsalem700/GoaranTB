#include "stdio.h"
#include "lin_types.h"
#include "lin_sch.h"
#include "LIN_cfg.h"
#include "lin_hw.h"
#include "lin_master.h"
#include "lin_support.h"
#include "LIN.h"
static u8 enuSendFrameHeader(LIN_tstrMaster_frame *);
static u8 u8ClaculatePID(u8 u8FrameID);
static u8 u8CalculateCheckSum(LIN_tstrMaster_frame *pstrFrameCpy);
static u8 enuSendDataBaffer(LIN_tstrMaster_frame *psteCurrentFrame);
int lin_master_enuInit(void)
{
    printf("=> lin master Initialized\n");
    return 0;
}

int lin_master_enuMainFunction(void)
{
    u8 u8ExecutionResultLoc;
    lin_sch_vidScheduler();
    if (lin_sch_bIsNewFrameAvailable() == STD_TRUE)
    {
        LIN_tstrMaster_frame *psteCurrentFrame = lin_sch_pstrGetCurrentFrame();
        u8ExecutionResultLoc = enuSendFrameHeader(psteCurrentFrame);
        if (u8ExecutionResultLoc != 0)
        {
            if (psteCurrentFrame->slot.frame_type == LIN_FRAME_TYPE_Tx)
            {
                enuSendDataBaffer(psteCurrentFrame);
            }
            else
            {
            }
        }
    }
    return u8ExecutionResultLoc;
}
static u8 enuSendDataBaffer(LIN_tstrMaster_frame *psteCurrentFrame)
{
    u8 u8ExecutionResultLoc = 0;
    u8 *u8DataBufferLoc = psteCurrentFrame->slot.pu8DataBuffer;
    u8 u8DataBufferSizeLoc = psteCurrentFrame->slot.u8DataLength;

    lin_hw_write(u8DataBufferLoc, u8DataBufferSizeLoc);
    u8 u8CheckSumLoc = u8CalculateCheckSum(psteCurrentFrame);
    lin_hw_write(&u8CheckSumLoc, 1);

    return u8ExecutionResultLoc;
}
static u8 enuSendFrameHeader(LIN_tstrMaster_frame *pstrFrameCpy)
{

    u8 u8ExecutionResultLoc = lin_hw_enuSendBreak();
    u8 u8Byte = 0x55;
    u8ExecutionResultLoc |= lin_hw_write(&u8Byte, 1);
    u8Byte = u8ClaculatePID(pstrFrameCpy->slot.u8FrameId);
    u8ExecutionResultLoc |= lin_hw_write(&u8Byte, 1);
    return u8ExecutionResultLoc;
}

static u8 u8ClaculatePID(u8 u8FrameID)
{
    u8 result = 0;
    result = (u8)(BIT_GET(u8FrameID, 0) ^ BIT_GET(u8FrameID, 1) ^
                  BIT_GET(u8FrameID, 2) ^ BIT_GET(u8FrameID, 4))
             << OPEN_LIN_P0_FLAG;

    result |= (u8)(~(BIT_GET(u8FrameID, 1) ^ BIT_GET(u8FrameID, 3) ^
                     BIT_GET(u8FrameID, 4) ^ BIT_GET(u8FrameID, 5))
                   << OPEN_LIN_P1_FLAG);

    result |= (u8)(OPEN_LIN_ID_MASK & u8FrameID);
    return result;
}

static u8 u8CalculateCheckSum(LIN_tstrMaster_frame *pstrFrameCpy)
{
    u16 u16CheckSumLoc = 0;
    u8 byteIdx;
    u8 *pu8DataBufferLoc = pstrFrameCpy->slot.pu8DataBuffer;
    u8 u8DataLengthLoc = pstrFrameCpy->slot.u8DataLength;
    for (byteIdx = 0; byteIdx < u8DataLengthLoc; byteIdx++)
    {
        u16CheckSumLoc += pu8DataBufferLoc[byteIdx];
        if (u16CheckSumLoc > 0xFF)
        {
            u16CheckSumLoc -= 0xFF;
        }
        else
        {
            /* do nothing */
        }
    }
    return (u8)u16CheckSumLoc;
}