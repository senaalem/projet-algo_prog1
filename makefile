CC = gcc
CFLAGS = -c -g -Wall $(--cflags --libs)
EXE = main

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

$(EXE) : $(OBJ)
	@echo "\n* Construction de $@"
	$(CC) $^ -o $@ -lm
	
%.o : %.c
	$(CC) $(CFLAGS) $<
clean:
	rm -rf *.o 

