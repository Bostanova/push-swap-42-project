PUSH_SWAP	= push_swap
CHECKER		= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= 	push_swap.c check_args.c instr_rotate.c \
			instr_swap_push.c instr_rev_rotate.c \
			quick_sort.c fill_array.c initialization.c \
			sort_small.c sort_common.c sort_common_utils.c

SRC2 	= 	checker.c check_args.c instr_rotate.c \
			instr_swap_push.c instr_rev_rotate.c \
			quick_sort.c fill_array.c initialization.c

OBJ 	= obj
OBJ1 	= $(addprefix $(OBJ)/,$(SRC1:.c=.o))
OBJ2 	= $(addprefix $(OBJ)/,$(SRC2:.c=.o))

HDR 		= -I./includes
LIBFT_HDR 	= -I./libft

LIB_BIN	= -L./libft -lft
LIBFT		= ./libft/libft.a

all: $(LIBFT) ./libft/libft.a $(PUSH_SWAP) $(CHECKER)

LIBFT		= ./libft/libft.a

$(LIBFT):	
			make -C ./libft

$(OBJ):
	mkdir $@

$(OBJ)/%.o: %.c | $(OBJ)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(PUSH_SWAP): $(OBJ1) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJ1) $(LIB_BIN) -o $@

$(CHECKER): $(OBJ2) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJ2) $(LIB_BIN) -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(PUSH_SWAP)
	/bin/rm -f $(CHECKER)
	make -C ./libft fclean

re: fclean all

