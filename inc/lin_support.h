#pragma once
#include "lin_types.h"
#define BIT_GET(x, y) (((x) >> (y)) & 0x01u)
#define OPEN_LIN_ID_MASK 0x3Fu
#define OPEN_LIN_P0_FLAG 6
#define OPEN_LIN_P1_FLAG 7