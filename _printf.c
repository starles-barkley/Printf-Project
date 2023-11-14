#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    if (format == NULL) {
        return -1; // Handle NULL format string
    }

    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format != '\0') {
        if (*format != '%') {
            putchar(*format);
            count++;
        } else {
            format++;
            if (*format == '\0') {
                break; // Format ends with '%', handle it as needed
            }

            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    if (s != NULL) {
                        while (*s != '\0') {
                            putchar(*s);
                            s++;
                            count++;
                        }
                    } else {
                        // Handle NULL string pointer
                        printf("(null)");
                        count += 6;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default: {
                    // Handle unsupported format specifier
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
                }
            }
        }
        format++;
    }
    va_end(args);
    return count;
}