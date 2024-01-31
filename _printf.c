#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int simple_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; 
    
    while (*format) {
        if (*format == '%') {
            format++;
            
            
            if (*format == 'c') {
                int myChar = va_arg(args, int);
                putchar(myChar);
                count++;
            } else if (*format == 's') {
                const char *currentStr = va_arg(args, const char *);
                fputs(currentStr, stdout);
                count += strlen(currentStr);
            } else if (*format == '%') {
                putchar('%');
                count++;
            }else if (*format == 'd') {
                int myChar = va_arg(args, int);
                putchar(myChar);
                count++;
            } 
            else {

                break;
            }
        } else {

            putchar(*format);
            count++;
        }

        format++; 
    }

    va_end(args);
    return count;
}
