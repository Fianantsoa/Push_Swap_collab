*This project has been created as part of the 42 curriculum by finoment.*

## Description

Libft is a custom C library developed as a first step into low-level programming at 42.
The goal of this project is to reimplement a set of standard C library functions, as well
as additional utility functions such as linked list manipulation.

### Objective
The main goals of this project are to:
- Understand the internal behavior of standard C library (libc) functions
- Manipulate strings, memory, and linked lists in C
- Learn how to design, structure, and maintain a reusable C library
- Reuse this library in future projects of the 42 curriculum

## Installation & Compilation

### Installation
First, clone the repository:
```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-a9aecd4e-972d-4efa-b1bd-d514663de489-7240777-finoment libft
cd libft
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
This will generate a ```libft.a``` static library.

Other orders :
```bash
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Rebuild the library from scratch
```
### Usage

Include the header in your C files : 
```c
#include "libft.h"
```

Compile your project with : 
```bash
cc -Wall -Wextra -Werror main.c -L. -lft
```

This command enables warnings, treats them as errors, compiles `main.c`,
and links the `libft` library located in the current directory.

Example usage:

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strdup("Hello 42!");
    ...
    return 0;
}
```
## Resources

### Classic References 
- Linux manual pages (man malloc, free, write)   
- W3Schools — C programming tutorials  
- Tutorialspoint — C programming guides and references  
- Portfolio Courses (YouTube) 
- 42 Network subject PDFs and official documentation  

### AI Usage
AI tools were used as an educational aid to better understand the project requirements
and core C concepts. This includes asking the AI to explain Linux manual pages
(such as malloc, free, and write), in order to better understand their behavior and usage.

The AI was also used to clarify how singly linked lists work, including their memory
representation and pointer relationships. Additionally, explanations were requested
regarding Makefile structure, common rules, and best practices.

All code was implemented, tested, and debugged manually by the author.
The AI was used strictly for explanations and learning purposes, not for generating
final implementations.

## Library Overview

The Libft library is a custom implementation of essential C standard library functions,
along with additional utility functions and data structure helpers. It is divided into
three main parts, each targeting a specific aspect of C programming fundamentals.

### Organization
- Each function is implemented in its own `.c` file.
- Function prototypes are declared in the `libft.h` header file
- The compilation process generates a static library named `libft.a`

### Part 1 – Libc Functions

This part includes reimplementations of commonly used functions from the C standard
library. These functions focus on string manipulation, memory handling, and basic
character checks.

| Function     | Return value | Description                                              |
| ------------ | ------------ | -------------------------------------------------------- |
| `ft_isalpha` | `int`        | Checks if the character is an alphabetical letter.       |
| `ft_isdigit` | `int`        | Checks if the character is a digit (0–9).                |
| `ft_isalnum` | `int`        | Checks if the character is alphanumeric.                 |
| `ft_isascii` | `int`        | Checks if the character is a valid ASCII character.      |
| `ft_isprint` | `int`        | Checks if the character is printable.                    |
| `ft_strlen`  | `size_t`     | Returns the length of a string.                          |
| `ft_memset`  | `void *`     | Fills a block of memory with a given value.              |
| `ft_bzero`   | `void`       | Sets a block of memory to zero.                          |
| `ft_memcpy`  | `void *`     | Copies memory from source to destination.                |
| `ft_memmove` | `void *`     | Copies memory handling overlapping areas safely.         |
| `ft_strlcpy` | `size_t`     | Copies a string with size limitation.                    |
| `ft_strlcat` | `size_t`     | Concatenates strings with size limitation.               |
| `ft_toupper` | `int`        | Converts a lowercase letter to uppercase.                |
| `ft_tolower` | `int`        | Converts an uppercase letter to lowercase.               |
| `ft_strchr`  | `char *`     | Locates the first occurrence of a character in a string. |
| `ft_strrchr` | `char *`     | Locates the last occurrence of a character in a string.  |
| `ft_strncmp` | `int`        | Compares two strings up to a given number of characters. |
| `ft_memchr`  | `void *`     | Searches for a character in a memory block.              |
| `ft_memcmp`  | `int`        | Compares two memory blocks.                              |
| `ft_strnstr` | `char *`     | Locates a substring within a string.                     |
| `ft_atoi`    | `int`        | Converts a string to an integer.                         |
| `ft_calloc`  | `void *`     | Allocates memory and initializes it to zero.             |
| `ft_strdup`  | `char *`     | Duplicates a string using dynamic memory allocation.     |

### Part 2 – Additional Functions

This section contains additional utility functions that are not part of the standard C
library but are commonly used in C projects. These functions focus on string processing
and dynamic memory allocation.

| Function        | Return value | Description                                                                |
| --------------- | ------------ | -------------------------------------------------------------------------- |
| `ft_substr`     | `char *`     | Extracts a substring from a string.                                        |
| `ft_strjoin`    | `char *`     | Concatenates two strings into a new string.                                |
| `ft_strtrim`    | `char *`     | Trims specified characters from the beginning and end of a string.         |
| `ft_split`      | `char **`    | Splits a string into an array of strings using a delimiter.                |
| `ft_itoa`       | `char *`     | Converts an integer to a string.                                           |
| `ft_strmapi`    | `char *`     | Applies a function to each character of a string and creates a new string. |
| `ft_striteri`   | `void`       | Applies a function to each character of a string using its index.          |
| `ft_putchar_fd` | `void`       | Writes a character to a file descriptor.                                   |
| `ft_putstr_fd`  | `void`       | Writes a string to a file descriptor.                                      |
| `ft_putendl_fd` | `void`       | Writes a string followed by a newline to a file descriptor.                |
| `ft_putnbr_fd`  | `void`       | Writes an integer to a file descriptor.                                    |


### Part 3 – Linked List Functions

The final part introduces functions to manipulate singly linked lists using a generic
t_list structure. These functions allow the creation, traversal, modification, and
destruction of linked lists.

| Function          | Return value | Description                                                |
| ----------------- | ------------ | ---------------------------------------------------------- |
| `ft_lstnew`       | `t_list *`   | Creates a new list node.                                   |
| `ft_lstadd_front` | `void`       | Adds a node at the beginning of a list.                    |
| `ft_lstadd_back`  | `void`       | Adds a node at the end of a list.                          |
| `ft_lstsize`      | `int`        | Returns the number of elements in a list.                  |
| `ft_lstlast`      | `t_list *`   | Returns the last element of a list.                        |
| `ft_lstdelone`    | `void`       | Deletes a single node and frees its content.               |
| `ft_lstclear`     | `void`       | Deletes and frees an entire list.                          |
| `ft_lstiter`      | `void`       | Applies a function to each element of a list.              |
| `ft_lstmap`       | `t_list *`   | Creates a new list by applying a function to each element. |

