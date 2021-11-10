#include "push_swap.h"

static int	separation(int *ar, int left, int right)
{
	int	pivot;
	int	i;
	int	tmp;

	pivot = ar[right];
	i = left - 1;
	while (left < right)
	{
		if (ar[left] <= pivot)
		{
			i++;
			tmp = ar[i];
			ar[i] = ar[left];
			ar[left] = tmp;
		}
		left++;
	}
	tmp = ar[i + 1];
	ar[i + 1] = ar[right];
	ar[right] = tmp;
	return (i + 1);
}

void	quick_sort(int *ar, int left, int right)
{
	int	tmp;

	if (left < right)
	{
		tmp = separation(ar, left, right);
		quick_sort(ar, left, tmp - 1);
		quick_sort(ar, tmp + 1, right);
	}
}
