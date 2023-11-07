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
	if (format != '\0')
	{
		int count = 0, i;
		int (*m)(va_list);
		va_list args;

		va_start(args, format);
		i = 0;
		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		while (format != '\0' && format[i] != '\0')
		{
			if (format[i] == '%')
			{
				if (format [i + 1] == '%')
				{
					count += _putchar(format[i]);
					i + 2;
				}
			}
		}
		else
		{
			count += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
return (-1);
