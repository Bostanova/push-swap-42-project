#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*tmp;

	if (argc < 2)
		return (0);
	a_stack = (t_stack *)malloc(sizeof(t_stack));
	create_stack(a_stack, argv, (argc - 1));
	tmp = a_stack;
	while (tmp->list != NULL)
	{
		printf("%d\n", tmp->list->content); //remove
		tmp->list = tmp->list->next;
	}
	printf("top = %d\n", tmp->top); //remove

	del_from_beg(a_stack->list);

	// ft_lstclear(&a_stack->list, 0);
	// free((void *)a_stack);
	return (0);
// 	sleep(1000);
}
