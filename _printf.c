int _printf(const char * const format, ...)

/* Implementation of the _printf function that takes a format string and variable number of arguments */
/* The format string specifies the format of the output string, with placeholders marked by conversion specifiers */
/* Returns the number of characters printed, or -1 if an error occurs */

{
    /* Definition of a struct array that maps conversion specifiers to their corresponding function */
    convert_match m[] = {
        {"%s", printf_string}, {"%c", printf_char},
        {"%%", printf_37},
        {"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
        {"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
        {"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
        {"%S", printf_exclusive_string}, {"%p", printf_pointer}
    };

    va_list args;
    int i = 0, j, len = 0;

    va_start(args, format);

    /* Check if the format string is null or empty */
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

Here:
    /* Loop through the format string and look for conversion specifiers */
    while (format[i] != '\0')
    {
        /* Loop through the array of conversion specifiers and call the corresponding function */
        j = 13;
        while (j >= 0)
        {
            if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
            {
                len += m[j].f(args);
                i = i + 2;
                goto Here;
            }
            j--;
        }
        /* If no conversion specifier is found, print the character */
        _putchar(format[i]);
        len++;
        i++;
    }

    va_end(args);
    return (len);
}
