#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include "main.h"
/**
 * printfisforfun - function that produces output according to a format
 * @format: character string that handles conversion specifiers
 * Return: void
 */
void printfisforfun(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else 
		{
			format++;
		}
			if (*format == 'c')
			{	
				int character = va_arg(args, int);
				putchar(character);
				count++;
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, const char *)
			}
				while (*str != '\0')
				{
					putchar(*str);
					count++;
					str++;
				}


}
