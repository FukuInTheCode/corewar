##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Placeholder
##

NAME   = corewar

CC	   = gcc

WFLAGS = -Wall -Wextra -Werror

LIBS = -lm -lc

CFLAGS = -I./include/ $(WFLAGS) $(LIBS)

SRC	= $(shell find src/ -type f -name "*.c")

OBJ	= $(SRC:src/%.c=obj/%.o)

RED = \033[1;31m

GREEN = \033[1;32m

BLUE = \033[1;34m

NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(BLUE)Compiling binary...$(NC)"
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

obj/%.o: src/%.c
	@echo -e "$(GREEN)Compiling $<...$(NC)"
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@if [ -d obj/ ]; then echo -e "$(RED)Cleaning objects.$(NC)"; fi
	@rm -rf obj

fclean: clean
	@if [ -e "$(NAME)" ]; then echo -e "$(RED)Cleaning binary.$(NC)"; fi
	@rm -f $(NAME)

tests_run:
	@echo -e "$(BLUE)Running tests...$(NC)"

d: debug

debug: CFLAGS += -g
debug: fclean $(NAME)
	@valgrind --log-file=/tmp/valgrind-$(NAME) --track-fds=all \
		--leak-check=full --show-leak-kinds=all ./$(NAME)
	@cat /tmp/valgrind-$(NAME)

re: fclean all
