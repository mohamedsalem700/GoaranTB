/**
 * File Name: TYP.h
 * Layer:	LIB
 * Description: This File has the Standard Types used by Application
 * Supplier:
 *
 * Copyright:
 * History:
 *	Date			|	Contributer			| Change:
 *	09/03/23		|	Mohamed Salem		| Initial
 *
 * */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
#include "string.h"
/* ==========================================================================
 * typedefs
 * ========================================================================== */
/**
 * Type u8
 * Size: 1 Byte
 * Range: [0 : 255]
 *
 * */
typedef unsigned char u8;
#define STD_u8MIN_VALUE ((u8)0)
#define STD_u8MAX_VALUE ((u8)0xFF)
/**
 * Type bool
 * Size: 1 Byte
 * Range: [0 : 1]
 *
 * */
typedef  u8 bool ;
/**
 * Type u16
 * Size: 2 Byte
 * Range: [0 : 65535]
 *
 * */
typedef unsigned short int u16;
#define STD_u16MIN_VALUE ((u16)0)
#define STD_u16MAX_VALUE ((u16)0xFFFF)
/**
 * Type u32
 * Size: 4 Byte
 * Range: [0 : 4,294,967,295]
 *
 * */
typedef unsigned long int u32;
#define STD_u32MIN_VALUE ((u32)0)
#define STD_u32MAX_VALUE ((u32)0xFFFFFFFF)
/**
 * Type s8
 * Size: 1 Byte
 * Range: [-128 : 127]
 *
 * */

typedef signed char s8;
#define STD_s8MIN_VALUE ((s8)-128)
#define STD_s8MAX_VALUE ((s8)127)
/**
 * Type s16
 * Size: 2 Byte
 * Range: [-32,768 : 32,767]
 *
 * */
typedef signed short int s16;
#define STD_s16MIN_VALUE ((s16)-32768)
#define STD_s16MAX_VALUE ((s16)32767)
/**
 * Type u32
 * Size: 4 Byte
 * Range: [-2,147,483,648 : 2,147,483,647]
 *
 * */
typedef signed long int s32;
#define STD_s32MIN_VALUE ((s32)-2147483648)
#define STD_s32MAX_VALUE ((s32)2147483647)


typedef enum
{
    STD_OK=0U,
    STD_INDEX_OUT_OF_RANGE_ERROR,
    STD_NULL_POINTER_ERROR,
    STD_NOK
}STD_tenuResult;


typedef void (*STD_tpfCallbackFunc)(void);

typedef STD_tenuResult (*STD_tpfInitFunc)(void);



typedef enum
{
    STD_FALSE,
    STD_TRUE
}STD_tBool;
typedef enum
{
    STD_IDLE,
    STD_BUSY

}STD_tenuState;
typedef struct
{
    u8 u8ErrorState;
    u8 u8ErrorCtr;
}STD_tsrCMPstate;
/* ==========================================================================
 * MaCROS
 * ==========================================================================*/
/**
 * NAME: LIB_STD_FALSE
 * VALUE: 0U
 *
 * */
#define STD_FALSE (0U)
/**
 * NAME: LIB_STD_TRUE
 * VALUE: 1U
 *
 * */
#define STD_TRUE (1U)

/**
 * NAME: STD_NULL_POINTER
 * VALUE: ((void *)0)
 *
 * */
#define STD_NULL_POINTER ((void *)0)
#define STD_OK 0U
#define STD_NOK 1U

#ifndef STD_NULL
  #define STD_NULL  (0U)
#endif

#endif /* * STD_TYPES_H_ */
