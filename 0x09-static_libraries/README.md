Creating a Static Library file
$ gcc -c *.c
$ ar -rc libname.a *.o
$ ranlib libname.a
ar -t libname.a
nm lib_test.a

-l<libraryname without lib prefix and extension>
-L : specifies the path to the library .We can use -L. inorder to point to the current directory and -L/home/tmp to point to the /home/tmp directory.
gcc main.c -L. -lname -o main
