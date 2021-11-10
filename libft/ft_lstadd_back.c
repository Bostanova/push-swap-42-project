#include "libft.h"

/*
	Adds the element ’new’ at the end of the list.

	**lst is the address of a pointer to the first link of a list.
	*new is the address of a pointer to the element to be
			added to the list.
*/

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (lst)
	{
		if (*lst)
		{
			tmp = *lst;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
		}
	}
}
