# ft_printf

A custom re-implementation of the standard `printf` function in C as part of the 42 curriculum. This project challenges you to manage formatted output in C using low-level functions and dynamic memory management.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [Bonus](#bonus)
- [Authors](#authors)
- [License](#license)

## Introduction

The `ft_printf` project is designed to recreate a subset of the functionality provided by the standard `printf` function in C. The goal is to gain a deep understanding of variable argument lists, memory management, and formatted output while writing clean, efficient, and maintainable code.

## Features

- **Formatted Output:** Supports common conversion specifiers such as `%d`, `%s`, `%c`, `%u`, `%x`, `%X`, and `%p`.
- **Custom Implementation:** Built from scratch without using the standard `printf` function.
- **Error Handling:** Gracefully handles invalid or unsupported format specifiers.
- **Modular Design:** Code is segmented into multiple files for better maintainability and clarity.

## Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Kingl25/ft_printf.git
   cd ft_printf
   ```

2. **Compile the Project:**

   Use the provided Makefile to compile all source files. Run:

   ```bash
   make
   ```

   This will produce the `ft_printf` executable (or library).

3. **Clean Up:**

   Remove compiled files when necessary with:

   ```bash
   make clean
   ```

## Usage

After compiling, you can use `ft_printf` in your projects. For example, create a test file such as:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Your score is %d%%.\n", "World", 100);
    return 0;
}
```

Compile your test file with:

```bash
gcc -o test your_test_file.c -L. -lft_printf
```

And run it:

```bash
./test
```

## Testing

Testing is crucial to ensure your implementation performs correctly:

- **Unit Tests:** Write tests for each conversion specifier to verify their outputs.
- **Edge Cases:** Consider testing with NULL pointers, zero values, and extreme integer limits.
- **Comparison:** Compare the output against the standard `printf` for consistency.

## Project Structure

A suggested layout for your project:

```
ft_printf/
├── includes/
│   └── ft_printf.h        # Header file(s)
├── src/
│   ├── ft_printf.c        # Main implementation file
│   ├── parser.c           # Format string parser
│   ├── printer.c          # Output handling
│   ├── utils.c            # Utility functions
│   └── ...                # Additional source files as needed
├── tests/
│   └── main.c             # Test suite
├── Makefile               # Compilation script
└── README.md              # Project documentation
```

## Bonus

For extra credit, consider implementing additional features such as:

- Support for floating-point conversion specifiers (`%f`, `%e`)
- Enhanced field width and precision handling
- Additional format flags like `-`, `+`, `0`, `#`, and space

Experiment with these features while staying within the project guidelines.

## Authors

- **Loic M.** – [GitHub Profile](https://github.com/Kingl25)

Special thanks to the 42 community and mentors for their support and inspiration.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
```

