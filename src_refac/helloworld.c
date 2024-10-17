//Chat GPT
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "quicksort.h"

#define MAX_INPUT_SIZE 1024  // "Endless"

// Function to read a character from UART
char uart_getc() {
    return inbyte();
}

// Function to send a character to UART
void uart_putc(char c) {
    outbyte(c);
}

// Function to send a string to UART
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

    while (1) {  // Loop to keep reading inputs and sorting
        input = uart_getc();
        if (input == '\r') {
            uart_puts("\r\n");
            if (count > 0) {
                numbers[count] = '\0';  // Null-terminate the string

                uart_puts("Original array: ");
                uart_puts(numbers);
                uart_puts("\r\n");

                sort(numbers);

                uart_puts("Sorted array: ");
                uart_puts(numbers);
                uart_puts("\r\n");
                count = 0;  // Reset count for new input batch
            } else {
                uart_puts("No characters entered.\r\n");
            }
        } else {
            if (count < MAX_INPUT_SIZE - 1) {
                numbers[count] = input;
                count++;
                uart_putc(input);  // Echo the input
            }
        }
    }

    cleanup_platform();
    return 0;
}
