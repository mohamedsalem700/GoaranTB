#pragma once

int UART_vidInit(void);
int UART_vidWrite(__uint8_t *buff, __uint8_t size);

int UART_vidRead(__uint8_t *buff, __uint8_t *size);

int UART_vidDeInit(void);