# libasm

This simple 42 project is an introduction to x86 ASM.

The goal is to rewrite simple function like :

- strlen
- strcmp
- strcpy

Unlike the previous version of tyhe subject, we aren't required to use repeat string instructions, hence why you won't see them used here.

However, some more complex functions can be written, especially those involving linked-lists.<br/>
While they aren't so complicated, they are at least more challenging to write.

## Building

To build, just issue :

~~~
$ make
$ make bonus
~~~

To clean :

~~~
$ make clean
~~~

or, if you want to clean the built library as well :

~~~
$ make fclean
~~~

## Using in C programs

If you want to use the ASM functions in your C program, just include `libasm.h` and/or `libasm_bonus.h`.

Note that this library is written for 64-bit x86 (System V 64-bit ABI).

## Testing

Unit-tests are provided. To run them, just issue :

~~~
$ ./tests/grademe.sh
~~~