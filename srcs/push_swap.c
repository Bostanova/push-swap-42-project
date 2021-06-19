#include "../includes/push_swap.h"
#include "../libft/libft.h"

void list_clear(t_list *head)
{
	t_list *tmp;
	
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
	t_stack *b;

	if (argc < 2)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	create_stack(a, argv, (argc - 1));
	b = (t_stack *)malloc(sizeof(t_stack));
	b->list = NULL;
	b->top = -1;
	if (sorted(a))
		sort_stack(a, b, (argc - 1));
	else
		ft_putstr("The stack is already sorted\n");
		
	// print list     //remove later
	// t_stack *tmp = a;
	// while (tmp->list != NULL)
	// {
	// 	printf("%d ", tmp->list->content);
	// 	tmp->list = tmp->list->next;
	// }
	// printf("\ntop_a = %d\n", tmp->top);
	// t_stack *tmp2 = b;
	// while (tmp2->list != NULL)
	// {
	// 	printf("%d ", tmp2->list->content);
	// 	tmp2->list = tmp2->list->next;
	// }
	// printf("\ntop_b = %d\n", tmp2->top);

	//free memory
	list_clear(a->list);
	free((void *)a);
	list_clear(b->list);
	free((void *)b);

	// return (0);
	// sleep(1000);
}
