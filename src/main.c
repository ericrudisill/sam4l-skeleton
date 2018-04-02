#include <asf.h>

#include <stdio.h>
#include <string.h>


clock_time_t f_log_timeout = 0;

static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
#ifdef CONF_UART_CHAR_LENGTH
		.charlength = CONF_UART_CHAR_LENGTH,
#endif
		.paritytype = CONF_UART_PARITY,
#ifdef CONF_UART_STOP_BITS
		.stopbits = CONF_UART_STOP_BITS,
#endif
	};

	/* Configure console UART. */
    sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}

int main(void)
{
    sysclk_init();
    board_init();
    delay_init();
    cph_millis_init();
    configure_console();

    puts("\r\n\r\nsam4l skeleton...\r\n");

    for (int i=0; i<10; i++) {
        printf(".");
        delay_ms(100);
    }
    printf("\r\n");

    while (true) {
        printf("Hello\r\n");     
        delay_ms(1000);
    }
}

