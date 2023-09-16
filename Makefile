CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = *.c
OUT = hsh

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
