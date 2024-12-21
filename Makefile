CC = gcc
CFLAGS = -Wall

all: sed_simplified

sed_simplified: main.o sed_operations.o
 $(CC) -o sed_simplified main.o sed_operations.o

main.o: main.c sed_operations.h
 $(CC) $(CFLAGS) -c main.c

sed_operations.o: sed_operations.c sed_operations.h
 $(CC) $(CFLAGS) -c sed_operations.c

clean:
 rm -f *.o sed_simplified

test:
 ./sed_simplified input.txt -r "old text" "new text"
