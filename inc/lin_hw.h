#pragma once

int lin_hw_enuInit(void);
int lin_hw_write(__uint8_t *buff, __uint8_t size);

int lin_hw_read(__uint8_t *buff, __uint8_t *size);

int lin_hw_deInit(void);
int lin_hw_enuSendBreak(void);