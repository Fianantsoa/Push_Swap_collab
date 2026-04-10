*This project has been created as part of the 42 curriculum by erakotom, finoment.*

## Description

`push_swap` is a project in the 42 curriculum that aims to **sort a stack of integers using a limited set of operations** while **minimizing the number of moves**.

The program takes a list of integers as arguments:

```bash
./push_swap [integers...]
```

It outputs a sequence of operations that sorts the stack in ascending order.

The allowed operations are:

* `sa`, `sb`, `ss` — swap the first two elements of a stack
* `pa`, `pb` — push the top element from one stack to another
* `ra`, `rb`, `rr` — rotate a stack upward
* `rra`, `rrb`, `rrr` — reverse rotate a stack downward

This project helps to understand:

* Stack manipulation using linked lists
* Algorithmic optimization under constraints
* Adaptive algorithm selection
* Input validation and memory management
* Performance benchmarking

---

## Instructions

### Installation

Clone the repository:

```bash
git clone <repository_url> push_swap
cd push_swap
```

---

### Compilation

Compile the project using:

```bash
make
```

This generates the executable:

```bash
./push_swap
```

---

### Usage

Run the program with a list of integers:

```bash
./push_swap 3 2 5 1 4
```

---

### Available options

The program supports different execution modes:

#### 🔹 Default mode (Adaptive)

```bash
./push_swap 3 2 5 1 4
```

* Automatically selects algorithm based on disorder
* Uses `ft_compute_disorder`
* Chooses best strategy dynamically

---

#### 🔹 Manual algorithm selection

```bash
./push_swap --simple [integers...]
```

* Forces **Selection Sort (O(n²))**

```bash
./push_swap --medium [integers...]
```

* Forces **Chunk Sort (O(n√n))**

```bash
./push_swap --complex [integers...]
```

* Forces **Radix Sort (O(n log n))**

---

#### 🔹 Benchmark mode

```bash
./push_swap --bench [integers...]
```

At the end of execution, displays statistics:

```bash
[bench] disorder: 49.75%
[bench] strategy: Complex / O(n log n)
[bench] total_ops: 15068
[bench] sa: 0 sb: 0 ss: 0 pa: 5068 pb: 5068
[bench] ra: 4932 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

---

### Makefile rules

```bash
make        # compile project
make clean  # remove object files
make fclean # remove objects + binary
make re     # recompile everything
```

---

## Resources

### Classic References

* 42 push_swap subject
* Linux manual pages
* W3Schools — C programming [https://www.w3schools.com/c/](https://www.w3schools.com/c/)
* Tutorialspoint C [https://www.tutorialspoint.com/cprogramming/index.htm](https://www.tutorialspoint.com/cprogramming/index.htm)

---

### AI Usage

AI tools were used for:

* Understanding sorting algorithms (selection sort, chunk sort, radix sort)
* Structuring documentation
* Explaining algorithm complexity and optimization strategies
* Improving README clarity and structure

All code and algorithm design were implemented manually.

---

## Algorithm and Data Structure Explanation

---

## Global Strategy

The project uses an **adaptive sorting system** that selects the best algorithm depending on:

* Level of disorder (`ft_compute_disorder`)
* Execution mode (simple / medium / complex / adaptive)

---

## Execution Modes

The program supports 4 modes:

### 🔹 `--simple`

Forces **Selection Sort**

* Complexity: O(n²)
* Best for nearly sorted inputs

---

### 🔹 `--medium`

Forces **Chunk-Based Sorting**

* Complexity: O(n√n)
* Best for medium disorder

---

### 🔹 `--complex`

Forces **Radix Sort**

* Complexity: O(n log n)
* Best for large / chaotic inputs

---

### 🔹 `--bench` (default optional debug mode)

Displays performance statistics:

* disorder percentage
* selected strategy
* total operations
* operation breakdown

---

## Benchmark Mode (Adaptive Rules)

When using `--adaptive` (default mode), the algorithm is selected using disorder:

| Disorder Level  | Condition            | Complexity | Algorithm      |
| --------------- | -------------------- | ---------- | -------------- |
| Low disorder    | disorder < 0.2       | O(n²)      | Selection Sort |
| Medium disorder | 0.2 ≤ disorder < 0.5 | O(n√n)     | Chunk Sort     |
| High disorder   | disorder ≥ 0.5       | O(n log n) | Radix Sort     |

---

## 🔹 1. Selection Sort (Low Disorder)

* Find smallest element
* Place it correctly
* Repeat until sorted

✔ Efficient for nearly sorted stacks
✔ Minimal overhead

---

## 🔹 2. Chunk-Based Sorting (Medium Disorder)

* Split stack into chunks (`t_chunk`)
* Push A → B by range
* Optimize rotations
* Rebuild sorted stack

✔ Balanced performance
✔ Reduces unnecessary moves

---

## 🔹 3. Radix Sort (High Disorder)

* Index values (`index_stack`)
* Sort bit by bit
* Move elements between stacks based on binary bits

✔ Very fast for large inputs
✔ Stable and predictable

---

## Algorithm Selection

Function `ft_algo_selector`:

1. Check CLI flags (`--simple`, `--medium`, `--complex`, `--adaptive`)
2. Compute disorder if needed
3. Select algorithm
4. Execute sorting

---

## Data Structures

### Main structure

```c
typedef struct s_data
{
    t_list      *stack_a;
    t_list      *stack_b;
    t_bench     bench;
    t_operation operations;
} t_data;
```

---

### Additional structures

* `t_chunk` → chunk management (start, end, size)
* `t_bench` → disorder, strategy, stats
* `t_operation` → counts each operation

---

## Benchmark System

Tracked values:

* total operations
* operation breakdown (`sa`, `pb`, `ra`, etc.)
* selected algorithm
* disorder percentage

Function:

* `ft_print_bench()` → prints benchmark report

---

## Algorithm Justification

This design ensures:

* Full control over algorithm choice
* Optimal performance per input type
* Clear separation between strategies
* Scalable architecture
* Compliance with 42 constraints

---

## Execution Flow

```
Input arguments
        ↓
Parse flags (--simple / --medium / --complex / --adaptive / --bench)
        ↓
Validate input
        ↓
Select algorithm
        ↓
Execute sorting
        ↓
Optional benchmark output
```

---

## Contributions

This project was developed collaboratively. Each member contributed to different parts of the implementation, design, and optimization.

__erakotom__
* Implementation of core stack operations (sa, pb, ra, etc.)
* Development of selection sort algorithm
* Parsing and input validation
* Initial project structure and architecture
* Benchmark system (t_bench, --bench mode)

__finoment__
* Implementation of chunk-based sorting algorithm
* Development of adaptive algorithm selector (ft_algo_selector)
* Memory management and error handling
* Writing and structuring documentation
* Creation and maintenance of the Makefile

__Shared work__
* Definition of project architecture and data structures (t_data, t_chunk, etc.)
* Debugging and performance improvements
* Testing on different input sizes and edge cases
* Implementation of radix sort algorithm
