CC=clang
CFLAGS=-g -Wall -Wextra -Werror -std=c11 -pedantic -O3 -fPIC


slice.o: ./utils/slice.c
	$(CC) $(CFLAGS) -c ./utils/slice.c -o ./utils/slice.o

echo: ./echo.o slice.o
	$(CC) $(CFLAGS) ./echo.o ./utils/slice.o -o echo; ./echo
