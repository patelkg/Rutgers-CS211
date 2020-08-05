all: third


search: third.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 third.c -o third

clean:
	rm -f third
