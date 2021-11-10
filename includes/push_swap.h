#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_list
{
	int				data;
	int				index_to_edge;
	int				half;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	int		top_a;
	int		top_b;
	int		min;
	int		max;
	int		med;
	t_list	*a;
	t_list	*b;
}	t_stacks;

typedef struct s_oper
{
	int	index_a;
	int	index_b;
	int	dir_a;
	int	dir_b;
}	t_oper;

typedef struct s_input_array
{
	int	a[10000];
	int	len;
}	t_input_array;

int		check_args(int argc, char **argv);
void	check_dupl(t_input_array *ar, t_stacks *stacks);
void	fill_array(int argc, char **argv, t_input_array *ar);
void	init_stack(t_input_array *ar, t_stacks *stacks);
void	free_stack(t_stacks *stacks);
void	init_array(t_stacks *stacks, t_input_array *ar);
void	sort_three(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
void	quick_sort(int *ar, int left, int right);
void	common_sort(t_stacks *stacks);
void	instr_count(t_stacks *s, t_oper *oper);
void	instr_begin(t_stacks *stacks, t_oper *steps);
void	rotate_a(t_list **a, int i);
void	rotate_b(t_list **b, int i);
void	rotate_ab(t_stacks *s, int i);
void	rev_rotate_a(t_list **a, int i);
void	rev_rotate_b(t_list **b, int i);
void	rev_rotate_ab(t_stacks *s, int i);
void	swap_a(t_list *a, int i);
void	swap_b(t_list *a, int i);
void	swap_ab(t_stacks *s, int i);
void	push_a(t_stacks *s, int i);
void	push_b(t_stacks *s, int i);

#endif
