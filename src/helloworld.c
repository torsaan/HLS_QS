#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "quicksort.h"

#define ARRAY_SIZE 10

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

    int numbers[ARRAY_SIZE];
    char input;
    int count = 0;

    uart_puts("Enter 10 single-digit numbers (0-9), then press Enter:\r\n");

    while (count < ARRAY_SIZE) {
        input = uart_getc();
        if (input >= '0' && input <= '9') {
            numbers[count] = input - '0';  // Convert char to int
            count++;
            uart_putc(input);  // Echo the input
            uart_putc(' ');
        } else if (input == '\r' && count == ARRAY_SIZE) {
            uart_puts("\r\n");
            break;  // Exit if Enter is pressed after 10 numbers
        } else if (input == '\r') {
            uart_puts("\r\nPlease enter all 10 numbers.\r\n");
        }
        // Ignore other inputs
    }

    uart_puts("Original array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        xil_printf("%d ", numbers[i]);
    }
    uart_puts("\r\n");

    sort(numbers, ARRAY_SIZE);

    uart_puts("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        xil_printf("%d ", numbers[i]);
    }
    uart_puts("\r\n");

    cleanup_platform();
    return 0;
}