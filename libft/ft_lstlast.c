#include "libft.h"

/* 	This function takes as input a beginning of the list.
	Returns the last element of the list   */

t_lst	*ft_lstlast(t_lst *lst)
{
	t_lst	*res;
	t_lst	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		res = tmp;
		tmp = tmp->next;
	}
	return (res);
}
