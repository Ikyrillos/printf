#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - A function that prints formatted output to stdout
 * @format: The format string.
 *
 * Return: The number of characters printed, or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);

    char buffer[BUFF_SIZE];
    int buff_ind = 0, printed_chars = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format = handle_print(format, &buff_ind, list, buffer);
            if (format == NULL)
                return -1;
        }
        else
        {
            buffer[buff_ind++] = *format++;
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);
    return printed_chars;
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);
    *buff_ind = 0;
}
