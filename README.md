*This project has been created as part of the 42 curriculum by finoment.*

## Description

`push_swap` is a project in the 42 curriculum that aims to **sort a stack of integers using a limited set of operations** and **minimize the number of moves**.

The main goal is to create a program:

```bash
./push_swap [integers...]
```

The program receives a list of integers as command-line arguments and outputs a series of operations that sorts the stack in ascending order. The operations allowed are:

* `sa`, `sb`, `ss` — swap the first two elements of a stack
* `pa`, `pb` — push the top element from one stack to the other
* `ra`, `rb`, `rr` — rotate a stack upward
* `rra`, `rrb`, `rrr` — reverse rotate a stack downward

This project helps you understand and master:

* Stack manipulation using arrays or linked lists
* Algorithmic optimization (reducing the number of moves)
* Conditional logic and decision-making
* Handling edge cases and input validation
* Memory management in C

In summary, `push_swap` is a fundamental C algorithmic project that develops your understanding of data structures, sorting logic, and efficient computation.

---

## Instructions

### Installation

First, clone the repository:

```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-xxxx push_swap
cd push_swap
```

> Note: The repository URL may change depending on the project or user.
> The general format is:

```bash
git clone <repository_url> <folder_name>
cd <folder_name>
```

---

### Usage

Compile your project using the Makefile:

```bash
make
```

This will generate the executable:

```bash
./push_swap
```

---

Run your program with a list of integers:

```bash
./push_swap 3 2 5 1 4
```

Example output:

```bash
pb
pb
sa
pa
pa
```

> Each line represents an operation used to sort the stack with the minimal number of moves.

---

### Additional commands

```bash
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Recompile the project
```

---

## Resources

### Classic References

* Linux manual pages (`man malloc`, `man write`, `man exit`)
* W3Schools — C programming tutorials [https://www.w3schools.com/c/](https://www.w3schools.com/c/)
* Tutorialspoint C [https://www.tutorialspoint.com/cprogramming/index.htm](https://www.tutorialspoint.com/cprogramming/index.htm)

### AI Usage

AI is used solely as an educational tool to understand `push_swap` logic and structure documentation. It does not implement code or make algorithmic decisions.

* Helps explain stack operations and sorting logic
* Assists in understanding algorithm optimization
* Clarifies project constraints and edge cases

All code is manually implemented by the student.

---

## Algorithm and Data Structure Explanation

### 🧩 Algorithm Explanation

#### Algorithm Structure

1. **Input validation**:

   * Parse command-line arguments and check for invalid integers or duplicates.
   * Return an error if the input is invalid.

2. **Stack initialization**:

   * Store integers in a **stack A**.
   * Initialize **stack B** as empty.

3. **Sorting logic**:

   * Depending on the size of the stack, apply different sorting strategies:

     * Small stacks (2–5 elements): hardcoded minimal moves
     * Larger stacks: optimized algorithm using rotations, swaps, and pushes

4. **Operations execution**:

   * Push, swap, rotate, and reverse rotate operations manipulate stacks according to the sorting strategy.
   * Record and print operations in the order they are executed.

5. **Utility functions**:

   * Functions like `swap()`, `push()`, `rotate()`, and `reverse_rotate()` are implemented separately in utility files to maintain clean code and readability.

---

#### Algorithm Justification

* **Efficiency**: Uses minimal moves for stack sorting.
* **Modularity**: Stack operations are separated into utility functions.
* **Scalability**: Handles small and large inputs with appropriate algorithms.
* **Memory safety**: Proper dynamic allocation and deallocation prevent leaks.
* **Compliance with 42 standards**: Meets all project requirements (sorting with stack operations, input validation, optimized moves).

---

#### Simplified Algorithm Diagram

```
[input args] ---> validate input ---> stack A
                               \
                                ---> stack B (temporary)
sort algorithm ---> execute operations ---> output operations
```

---