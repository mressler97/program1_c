#make file

CC=gcc
TARGET=main

all:	main.o readClasses.o parse.o prints.o UserQuery.o
	$(CC) main.c readClasses.c parse.c prints.c UserQuery.c -o $(TARGET)

