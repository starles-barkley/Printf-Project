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
    char *p; /* basic pointer to current character in format string */
    char *sp; /* pointer to current character in string arg */
    char *bp; /* pointer to current character in buffer */
    char buffer[100]; /* char array that holds the converted integer as a string */

    va_start(args, format); /* initializes va_list object args for _printf */
    p = (char *)format; /* format string assigned to pointer */

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

            if (*p == '\0')
            {
                _putchar('%');
                count++;
                break;
            }
            if (*p == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
            }
            else if (*p == 's')
            {
                char *s = va_arg(args, char *); /* retrieves next argument from variable argument list args and interprets it as char* */
                sp = s; /* assigns string pointer to current character in string */

                while (*sp != '\0')
                {
                    _putchar(*sp);
                    count++;
                    sp++;
                }
            }
            else if (*p == '%')
            {
                _putchar('%');
                count++;
            }
            else if (*p == 'd' || *p == 'i') /* checking if next character is d or i */
            {
                int i = va_arg(args, int); /* retrieves next argument from variable argument list args and interprets it as int */
                sprintf(buffer, "%d", i); /* convert the integer to a string and store it in the buffer */
                bp = buffer; /* buffer pointer becomes current character in buffer */
                while (*bp != '\0')
                {
                    _putchar(*bp);
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
        p++;
    }
    va_end(args);
    return (count);
}
