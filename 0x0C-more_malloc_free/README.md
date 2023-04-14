The malloc function is used to allocate a certain amount of memory during the execution of a program. It will request a block of memory from the heap. If the request is granted, the operating system will reserve the requested amount of memory and malloc will return a pointer to the reserved space.

When the amount of memory is not needed anymore, you must return it to the operating system by calling the function free.

Valgrind
When writing big and complex programs, it is not always easy to keep track of all allocated and deallocated memory. We can use the program Valgrind in order to ensure we are freeing all allocated memory. It is a programming tool for memory debugging, memory leak detection, and profiling.

String literals and .rodata (advanced)
The string literals are stored in your executable at compilation. The way it is stored is actually dependent on both the operating system you are using and the linker. This is what happens when you compile the program on most modern operating systems:
The compiler puts the string into a read-only data-section, usually .rodata
The linker collects all the data in such read-only sections and puts them into a single segment. This segment resides in the executable file and is flagged with a “read only”-attribute.

So how does the program know what to print, without actually using the string? Well, sometimes (actually more often than you think), the compiler will optimize your code and modify it, without telling you. Let’s analyse what happens with objdump:
julien@ubuntu:~/c/strings$ objdump -d -Mintel ps

Note that if you look at the strings of the executable with strings you will find the string HolbertoH.
julien@holberton:~/c/strings$ strings ph | grep HolbertoH
HolbertoH
