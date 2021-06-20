#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	list_clear(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(head);
		head = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	create_stack(a, argv, (argc - 1));
	b = (t_stack *)malloc(sizeof(t_stack));
	b->list = NULL;
	b->top = -1;
	b->tail = INT32_MAX;
	if (sorted(a))
		sort_stack(a, b);
	list_clear(a->list);
	free((void *)a);
	list_clear(b->list);
	free((void *)b);
	return (0);
}
