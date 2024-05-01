##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for amazed
##

NAME = corewar

CC = gcc

FLAGS =  -Wall -Wextra -I./include -g

SRC = $(shell find src/ -type f -name "*.c")

OBJ = $(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME):	$(OBJ)
			 $(CC) $(FLAGS) -o $(NAME) $(OBJ)

obj/%.o: src/%.c
		@mkdir -p $(dir $@)
		@$(CC) -c -o $@ $< $(FLAGS)

clean:
		@rm -rf obj

fclean: clean
		@rm -f $(NAME)

re: fclean all
