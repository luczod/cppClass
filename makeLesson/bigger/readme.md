#### How to Compile a Bigger C Program
```shell
gcc -o main main.c random.c -lm
```

```shell
gcc -c main.c
gcc -c random.c
gcc -o main main.o random.o -lm
```

- Output filename
- Source file 1
- Source file 2
- Link with maths library

#### Make
A few soruce code files can potentially be mange and compiled by hand. But at some point you are going to need some automation.
- A useful tool like 'htop' has 128 .c files, plus all the .h files

```shell
more Makefile
make
./hellow
make clean
make all
make hellow
```
