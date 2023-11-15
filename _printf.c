#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: character string that handles conversion specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *p;

    va_start(args, format);
    for (p = (char *)format; *p != '\0'; p++)
    {
        if (*p != '%')
        {
            _putchar(*p);
            count++;
        }
        else
        {
            p++;
            if (*p == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
            }
            else if (*p == 's')
            {
                char *s = va_arg(args, char *);
                char *sp;

                for (sp = s; *sp != '\0'; sp++)
                {
                    _putchar(*sp);
                    count++;
                }
            }
            else if (*p == '%')
            {
                _putchar('%');
                count++;
            }
            else
            {
                _putchar('%');
                _putchar(*p);
                count += 2;
            }
        }
    }
    va_end(args);
    return (count);
}