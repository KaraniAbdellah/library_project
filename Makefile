CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = main.c user.c employee.c myLib.c
OBJ = $(SRC:.c=.o)
EXEC = main

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXEC) $(OBJ)

