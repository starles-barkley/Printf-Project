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
    va_list args; /* variable of type va_list to hold variable arguments */
    int count = 0;
    char *p;
    char *sp;
    char *bp;
    char buffer[100];

    va_start(args, format);
    p = (char *)format;

    while (*p != '\0')
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
                sp = s;

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
            else if (*p == 'd' || *p == 'i')
            {
                int i = va_arg(args, int);
                sprintf(buffer, "%d", i);
                bp = buffer;
                while (*bp != '\0')
                {
                    putchar(*bp);
                    count++;
                    bp++;
                }
            }
            else
            {
                _putchar('%'); 
                _putchar(*p);
                count += 2; /* increments count variable by 2 as to not get stumped by % */
            }
        }
    }
    va_end(args);
    return (count);
}
