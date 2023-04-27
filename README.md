# Printf

_printf replicates the C standard library printf() function.

#### Prototype
```int _printf(const char *format, ...);```

#### Usage
* Prints a string to the standard output, according to a given format
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%

#### Compilation 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
