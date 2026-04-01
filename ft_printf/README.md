*This project has been created as part of the 42 curriculum by finoment.*

## Description

This project consists of implementing a custom version of `printf` in C, named `ft_printf`.  
The goal of the project is to understand variadic functions, memory management, type promotion, and formatted output in C.  
It provides support for multiple format specifiers, such as `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

The project allows a deeper understanding of:

- How variadic functions work with `va_list`, `va_start`, `va_arg`, and `va_end`.
- How type promotion affects variadic arguments (e.g., `char` and `short` promoted to `int`, `float` to `double`).
- Converting integers and pointers to strings in decimal and hexadecimal formats.
- Handling edge cases like `NULL` pointers and integer limits.

## Instructions

### Installation
First, clone the repository:
```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-1fbf5c08-938c-4748-acd7-499fdf585632-7267754-finoment libftprintf
cd libftprintf
```
Note: The repository link may change depending on the project or user.
In general, the command follows this format:
```bash
git clone <repository_url> <folder_name>
cd <folder_name>
```

### Compilation

To compile the library, run :

```bash
make
```
This will generate a ```libftprintf.a``` static library.

Other orders :
```bash
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Rebuild the library from scratch
```
### Usage

Include the header in your C files : 
```c
#include "ft_printf.h"
```

Compile your project with : 
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o main
```

This command enables warnings and treats them as errors, compiles `main.c`, and links it with the `libftprintf` library in the current directory and the `libft` library located in libft/libft.a.

Example usage:

```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Hello %s, number: %d, hex: %x\n", "World", 42, 255);
    return 0;
}
```

Execution
```bash
./main
```

## Resources

### Classic References 
- Linux manual pages (man printf, free, write, malloc)
- W3Schools — C programming tutorials https://www.w3schools.com/c/
- Tutorialspoint C https://www.tutorialspoint.com/cprogramming/index.htm

### AI Usage
AI was used as a learning and guidance tool to better understand specific concepts of the project, including:

Clarifying type promotion rules in variadic functions (char and short promoted to int, float to double), so that arguments are handled correctly with va_arg.

Generating examples of test cases for all supported % format specifiers, helping to ensure edge cases and proper output formatting.

Explaining algorithms for converting pointers and integers to strings without using printf, including how to handle hexadecimal and decimal conversions manually.

Important: No AI-generated code was directly copied into the project. All implementations, testing, and final code were written manually, relying on AI only for explanations, examples, and guidance.

## Algorithm and Data Structure Explanation

### General Approach
The goal of `ft_printf` is to reproduce the behavior of the standard C function `printf from the C standard library`.
The chosen approach is based on:
- Sequential parsing of the format string
- Detection of format specifiers (`%d`, `%s`, `%x`, etc.)
- Dispatching conversion handling through a modular design

The algorithm processes the format string character by character from left to right.

### Chosen Algorithm
#### Step-by-step Logic
- Initialize a counter for the number of printed characters.
- Iterate through the format string.
- If the current character is not %:
    * Write it directly to stdout.
    * Increment the printed character counter.
- If the current character is %:
    * Move to the next character.
    * Identify the conversion type.
    * Call the corresponding conversion function.
    * Add the number of printed characters to the total count.
- Return the total printed characters.

#### Why This Algorithm?

- [ Efficiency ] No unnecessary memory allocations for parsing.
- [ Clarity ] The logic closely mirrors how the real printf works.

#### Data Structures Used
##### Variadic Arguments (va_list)
The core data structure used is:
```c
va_list args;
```
This allows the function to accept a variable number of arguments.
Why va_list?
- Required to replicate printf
- Efficient access to arguments
- Standard C mechanism for variadic functions

##### Functions
- `ft_ltoh` converts a `decimal` number into a lowercase `hexadecimal` representation in string form (useful, for example, for `%x` or `%p` in `ft_printf`).
- `ft_n_show_c` is used to determine how many characters will be displayed to represent a number (useful in ft_printf `to know how many characters to write`).
- `ft_putunbr_fd` displays an `unsigned int` number digit by digit in a given file descriptor.
It uses a recursive method to write each digit in base 10, which allows `large unsigned numbers to be displayed correctly`, unlike ft_putnbr_fd from libft, which only handles signed integers.
- `ft_strupcase` is used to convert a character string to uppercase. It is `used in the management of the %X format` in ft_printf, in order to transform hexadecimal letters (from a-f to A-F) before displaying the hexadecimal number in uppercase.