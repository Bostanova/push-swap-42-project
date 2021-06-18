#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //don't forget to remove
# include "../libft/libft.h"

typedef struct s_stack
{
	t_list	*list;
	int		top;
}	t_stack;

void	create_stack(t_stack *stack, char **argv, int len);

#endif