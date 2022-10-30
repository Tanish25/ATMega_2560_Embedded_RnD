//#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BAUDRATE           115200L
#define SERIAL_FORMAT_8N1  0x06

FILE* uart_init(void);
static int uart_putc(char c, FILE *stream);

static FILE outfile = FDEV_SETUP_STREAM(uart_putc, NULL, _FDEV_SETUP_WRITE);

int main(void) 
{
    stdout = uart_init();
    DDRC |= (1<<DDC0);
//pin C0 is pin37 on board
    while(1)
    {
        PORTC |= (1<<PORTC0);
        _delay_ms(1000);
        printf("hello\n");

        PORTC &= ~ (1<<PORTC0);
        _delay_ms(1000);
        printf("world\n");
    }
}

FILE* uart_init(void)
{
    /* configure UART0 baudrate */
    UBRR0H = 0;
    UBRR0L = (uint8_t) (F_CPU / 4 / BAUDRATE - 1) / 2;

    /* set UART0 control and status registers (UCSR0x) */
    UCSR0A |= (1 << U2X0); /* double the transmission speed */
    UCSR0B |= (1 << TXEN0);
    UCSR0C  = SERIAL_FORMAT_8N1;

    return &outfile;
}

static int uart_putc(char c, FILE *stream) 
{
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = (uint8_t)c;
    return c;
}