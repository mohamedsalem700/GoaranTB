#pragma once

void lin_sch_vidInit(void);
void lin_sch_vidScheduler(void);
LIN_tstrMaster_frame *lin_sch_pstrGetCurrentFrame(void);
bool lin_sch_bIsNewFrameAvailable(void);
