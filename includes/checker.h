#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

typedef struct s_stack
{
	int	*data;
	int	top;
}	t_stack;

void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *a, t_stack *b);
int		ft_error(void);
void	create_a(t_stack *a, int len, char **argv);
void	call_cmd(char *cmd, t_stack *a, t_stack *b);

#endif