#include "libft.h"

/*   Create a new node of linked list      */

t_lst	*ft_lstnew(void *content)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(sizeof(t_lst));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
