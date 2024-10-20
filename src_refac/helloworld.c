//Chat GPT
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "quicksort.h"

#define MAX_INPUT_SIZE 1024  // Arbitrary large size for endless input


char uart_getc() {
    return inbyte();
}


void uart_putc(char c) {
    outbyte(c);
}


void uart_puts(const char* s) {
    while (*s != '\0') {
        uart_putc(*s++);
    }
}

int main() {
    init_platform();

    char numbers[MAX_INPUT_SIZE] = {0};
    char input;
    int count = 0;

    uart_puts("Enter characters (including numbers or letters), press Enter after each batch to sort:\r\n");

    while (1) {  
        input = uart_getc();
        if (input == '\r') {
            uart_puts("\r\n");
            if (count > 0) {
                numbers[count] = '\0'; 

                uart_puts("Original array: ");
                uart_puts(numbers);
                uart_puts("\r\n");

                sort(numbers);

                uart_puts("Sorted array: ");
                uart_puts(numbers);
                uart_puts("\r\n");
                count = 0;  
            } else {
                uart_puts("No characters entered.\r\n");
            }
        } else {
            if (count < MAX_INPUT_SIZE - 1) {
                numbers[count] = input;
                count++;
                uart_putc(input);  
            }
        }
    }

    cleanup_platform();
    return 0;
}
