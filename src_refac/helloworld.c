//Chat GPT
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "quicksort.h"

#define ARRAY_SIZE 11 //10 numbers then enter 
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

    char numbers[ARRAY_SIZE];
    char input;
    int count = 0;

    uart_puts("Enter 10 single-digit numbers (0-9), then press Enter:\r\n");

    while (count < ARRAY_SIZE - 1) {
        input = uart_getc();
        if (input >= '0' && input <= '9') {
            numbers[count] = input;
            count++;
            uart_putc(input);  // Echo the input
            uart_putc(' ');
        } else if (input == '\r' && count == ARRAY_SIZE - 1) {
            uart_puts("\r\n");
            break;  // Exit if Enter is pressed after 10 numbers
        } else if (input == '\r') {
            uart_puts("\r\nPlease enter all 10 numbers.\r\n");
        }
        // Ignore other inputs
    }
    numbers[ARRAY_SIZE - 1] = '\0';  // Null-terminate the string

    uart_puts("Original array: ");
    uart_puts(numbers);
    uart_puts("\r\n");

    sort(numbers);

    uart_puts("Sorted array: ");
    uart_puts(numbers);
    uart_puts("\r\n");

    // New code to wait for input after sorting
    uart_puts("Press any key to exit...\r\n");
    uart_getc();  // Wait for a single character input

    cleanup_platform();
    return 0;
}