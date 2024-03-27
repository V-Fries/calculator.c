# calculator.c

This is a simple calculator program written in C. It accepts mathematical expressions as command line arguments and evaluates them.

## Usage

The program expects a mathematical expression as a command line argument. Each element (numbers, operators, parentheses) should be separated by a space.

Here is an example of how to use the program:

```bash
./calculator "( ( 54 + 4 ) / 2 ) * 2"
```

This will evaluate the expression ((54 + 4) / 2) * 2 and print the result.

## Limitations

The program only supports basic arithmetic operations: addition, subtraction, multiplication, and division. It does not support exponentiation, roots, or other advanced mathematical operations.

Also, the program does not perform any error checking. If the input expression is not properly formatted, the program may produce incorrect results or crash.
