NAME = pathfinder

SRCR = *.c

OBJR = $(SRCR:.c=.o)

LIB = libmx/libmx.a

all:
	@make -C libmx
	@mkdir obj
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c -g src/*.c
	@mv $(OBJR) obj
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -g obj/*.o $(LIB) -o $(NAME)

uninstall: clean
	@rm -rf $(NAME)
	@rm -rf libmx/libmx.a

clean:
	@rm -rf obj
	@make clean -C libmx

reinstall: uninstall all
