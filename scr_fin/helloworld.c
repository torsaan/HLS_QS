#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "quicksort.h"
#include "xil_cache.h"
#include "xpseudo_asm.h"

#define MAX_INPUT_SIZE 1024  // Arbitrary large size for endless input

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

// Function to enable PMCCNTR
void enable_pmccntr() {
    // Enable user mode access to PMCCNTR
    mtcp(XREG_CP15_COUNT_ENABLE_SET, 0x80000000);

    // Reset PMCCNTR
    mtcp(XREG_CP15_PERF_CYCLE_COUNTER, 0);
}

// Function to get PMCCNTR value
unsigned int get_pmccntr() {
    unsigned int count;
    count = mfcp(XREG_CP15_PERF_CYCLE_COUNTER);
    return count;
}

int main() {
    init_platform();

    char numbers[MAX_INPUT_SIZE] = {0};
    char input;
    int count = 0;
    unsigned int sort_start, sort_end;

    enable_pmccntr();

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

                Xil_DCacheFlush();  // Flush data cache before measurement
                sort_start = get_pmccntr();
                sort(numbers);
                sort_end = get_pmccntr();
                Xil_DCacheFlush();  // Flush data cache after measurement

                uart_puts("Sorted array: ");
                uart_puts(numbers);
                uart_puts("\r\n");

                unsigned int cycles_taken = sort_end - sort_start;
                xil_printf("Cycles taken to sort: %u\r\n", cycles_taken);

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
