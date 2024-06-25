// C library headers
#include <stdio.h>
#include <string.h>

// Linux headers
#include <fcntl.h>   // Contains file controls like O_RDWR
#include <errno.h>   // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h>  // write(), read(), close()
#include "UART.h"
extern int serial_port;
int main()
{
    UART_vidInit();

    char *msg = {"Hello all"};
    UART_vidWrite((__uint8_t* )msg, 5);
    // Allocate memory for read buffer, set size according to your needs
    __uint8_t read_buf[256];

    // Normally you wouldn't do this memset() call, but since we will just receive
    // ASCII data for this example, we'll set everything to 0 so we can
    // call printf() easily.
    memset(&read_buf, '\0', sizeof(read_buf));
    __uint8_t num_bytes;
    UART_vidRead(read_buf, &num_bytes);

    // n is the number of bytes read. n may be 0 if no bytes were received, and can also be -1 to signal an error.
    if (num_bytes < 0)
    {
        printf("Error reading: %s", strerror(errno));
        return 1;
    }

    // Here we assume we received ASCII data, but you might be sending raw bytes (in that case, don't try and
    // print it to the screen like this!)
    printf("Read %i bytes. Received message: %s", num_bytes, read_buf);

     return 0; // success
}