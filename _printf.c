#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>



int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    va_start(args, format);


    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                }

                case 's': {
                    char *s = va_arg(args, char*);
                    fputs(s, stdout);
                    printed_chars += strlen(s);
                    break;
                }
                case '%': {
                    putchar('%');
                    printed_chars++;
                    break;
                }
                case 'd':
                {
                    int num = va_arg(args, int);
                    char buf[32];
                    printed_chars += sprintf(buf, "%d", num);
                    fputs(buf, stdout);
                    break;
                }

                case 'i': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    printed_chars += 1;
                    break;
                }

                 case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%u", num);
                    printed_chars += 1;
                    break;
                }

                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%x", num);
                    printed_chars += 1;
                    break;
                }
                case 'X': {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%X", num);
                    printed_chars++;
                    break;
                }

                case 'p': {
                    void *p = va_arg(args, void *);
                    printf("%p", p);
                    printed_chars += 1;
                    break;
                }
                
                case 'r': {
                    fputs("%r", stdout);
                    printed_chars++;
                    break;
                }

                case 'o': {
                    unsigned int num = va_arg(args, unsigned int);
                    char octal[32];
                    sprintf(octal, "%011o", num); 
                    printf("%s", octal);
                    printed_chars += strlen(octal) + 16; 
                    break;
                }


                default: {
                    printf("Invalid format specifier: %c\n", *format);
                    return -1;
                }
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}

