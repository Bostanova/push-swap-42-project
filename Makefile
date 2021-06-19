LIB_DIR		=libft/
LIB			=libft.a

NAME		=push_swap
SRC			=srcs/push_swap.c srcs/push.c srcs/reverse_rotate.c \
				srcs/rotate.c srcs/swap.c srcs/init.c srcs/sort.c
OBJ			=$(SRC:.c=.o)

FLAGS		= -Wall -Wextra -Werror
HEADER		=includes/push_swap.h

%.o:				%.c $(HEADER)
						@gcc $(FLAGS) -I$(LIB_DIR) -c $< -o $(<:.c=.o)
all:				$(NAME) 

$(NAME):			$(LIB_DIR)$(LIB) $(OBJ)
						@gcc $(OBJ) -I$(LIB_DIR) -L$(LIB_DIR) -lft $(MLXFLAGS) -o $(NAME)

$(LIB_DIR)$(LIB):	$(LIB_DIR)
						make -C $(LIB_DIR) all

clean:
						rm -rf $(OBJ)
						make -C $(LIB_DIR) clean

fclean:				clean 
						rm -rf $(NAME)
						make -C $(LIB_DIR) fclean

re:					fclean all

.PHONY:				all clean fclean re