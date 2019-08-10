NAME		= fillit

LIB_PATH	= ./libft/

LIB			= -L libft/ -lft

SRC			= src/main.c \
			src/reader.c \
			src/validator.c \
			src/sort_list.c \
			src/grid.c \
			src/solver.c

OBJ			= main.o \
			reader.o \
			validator.o \
			sort_list.o \
			grid.o \
			solver.o

FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH) all
	@gcc $(FLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJ)

fclean:
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re:	fclean all