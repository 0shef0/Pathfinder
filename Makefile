NAME = pathfinder

SRCR = *.c

OBJR = $(SRCR:.c=.o)

LIB = libmx/libmx.a

all:
	@make -C libmx
	@mkdir obj
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/*.c
	@mv $(OBJR) obj

install: all
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic obj/*.o $(LIB) -o $(NAME)

uninstall:
	@rm -rf libmx/libmx.a

clean: uninstall
	@rm -rf $(NAME)
	@rm -rf ./obj
	@make clean -C libmx

reinstall: clean install
