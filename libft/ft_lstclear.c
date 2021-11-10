#include "libft.h"

/*
**	Deletes and frees the given element and every successor 
**	of that element, using the function ’del’ and free(3).
**	The pointer to the list must be set to NULL
*/

void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst	*tmp;
	t_lst	*start;

	if (!lst || !del)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start->next;
		del(start->content);
		free(start);
		start = tmp;
	}
	*lst = NULL;
}
