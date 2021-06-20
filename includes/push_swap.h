#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h> //don't forget to remove
# include "../libft/libft.h"

typedef struct s_stack
{
	t_list	*list;
	int		tail;
	int		top;
}	t_stack;

void	create_stack(t_stack *stack, char **argv, int len);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_both(t_stack *stack1, t_stack *stack2);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_both(t_stack *stack1, t_stack *stack2);
void	rev_rotate_a(t_stack *tack);
void	rev_rotate_b(t_stack *tack);
void	rev_rotate_both(t_stack *stack1, t_stack *tack2);
void	sort_stack(t_stack *a, t_stack *b);
int		sorted(t_stack *stack);

#endif