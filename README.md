# Monty Interpreter

Monty Bytecode Interpreter was built in the C language as part of the requirement of Software Engineering course at Holberton School.

Monty is a scripting language that is first compiled to Monty ByteCode (just like in Python). It relies on a unique stack, with specific instructions to manipulate it. This project is a recreation of compiling simple Monty ByteCode files.

The interpreter can be run as either a stack (LIFO) or queue (FIFO).

## Installing and Using

Clone the repository into a new directory:

```
$ git clone https://github.com/EwarJames/monty.git
```
Compile with the following:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

Run the interpreter on a file:

```
./monty file
```
 where `file` is the path to the file containing Monty byte code

## Monty Opcodes handled and Explanations

* **push**
  * Usage: `push <int>`
  * Pushes an element to the stack.
  * The parameter `<int>` must be an integer.

* **pall**
  * Prints all values in the stack/queue, starting from the top.

* **pint**
  * Prints the top value of the stack/queue.

* **pop**
  * Removes the top element of the stack/queue.

* **swap**
  * Swaps the top two elements of the stack/queue.

* **nop**
  * Does not do anything.

* **add**
  * Adds the top two elements of the stack/queue.
  * The result is stored in the second element from the top and the top element is popped.

* **sub**
  * Subtracts the top element of the stack/queue from the second element from the top.
  * The result is stored in the second element from the top and the top element is removed.

* **mul**
  * Multiplies the top two elements of the stack/queue.
  * The result is stored in the second element from the top and the top element is removed.

* **div**
  * Divides the second element from the top of the stack/queue by the top element.
  * The result is stored in the second element from the top and the top element is removed.

* **mod**
  * Computes the modulus of the second element from the top of the stack/queue divided by the top element.
  * The result is stored in the second element from the top and the top element is removed.

* **pchar**
  * Prints the character value of the top element of the stack/queue.
  * The integer at the top is treated as an ASCII value.

* **pstr**
  * Prints the string contained in the stack/queue.
  * Prints characters element by element until the stack/queue is empty, a value is `0`, or an error occurs.

* **rotl**
  * Rotates the top element of the stack/queue to the bottom.

* **rotr**
  * Rotates the bottom element of the stack/queue to the top.

* **stack**
  * Switches a queue to stack mode.

* **queue**
  * Switches a stack to queue mode.

Opcodes preceeded by a `#` are treated as comments and the corresponding line is ignored.



## Authors

* **Ewar James** - [@EwarJames](https://github.com/EwarJames)

* **Okafor Nneka Tomiwa** - [@thormiwa](https://github.com/thormiwa)

