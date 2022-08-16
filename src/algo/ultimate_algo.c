#include "push_swap.h"

int ft_get_mediane(int *mediane, int *stack, int size)
{
    int *tmp_stack;
    int i;

    tmp_stack = (int *)malloc(size * sizeof(int));
    if (!tmp_stack)
        return (0);
    i = 0;
    while(i++ < size)
        tmp_stack[i] = stack[i];
    ft_sort_tmp(tmp_stack, size);
    *mediane = tmp_stack[size / 2];
    free(tmp_stack);
    return (1);
}

int ft_quicksort_a(t_stack *stack, int size)
{
    int mediane;
    int i;
    int swap;
    
    swap = 0;
    if (ft_check_sorted(stack->a, stack->size_a, ASCENDING) == TRUE)
        return (1);
    i = size;
    if (size <= 3)
    {
        ft_quicksort_3(stack, size);
        return (1);
    }
    if (!ft_get_mediane(&mediane, stack->a, stack->size_a))
        return (0);
    while (size != i / 2 + i % 2)
    {
        if (stack->a[0] < mediane && (size--))
			ft_pb(stack);
		else if (++swap)
			ft_ra(stack);
    }
    while (i / 2 + i % 2 != stack->size_a && swap--)
    	ft_rra(stack);
	return (ft_quicksort_a(stack, i / 2 + i % 2)
		&& ft_quicksort_b(stack, i / 2));
	return (1);
}

int	ft_quicksort_b(t_stack *stack, int size)
{
	int	mediane;
	int	i;
    int swap;

    swap = 0;
	if (ft_check_sorted(stack->b, size, DESCENDING) == 1)
		while (size--)
			ft_pa(stack);
	if (size <= 3)
	{
		ft_sort_small_b(stack, size);
		return (1);
	}
	i = size;
	if (!ft_get_mediane(&mediane, stack->b, stack->size_b))
		return (0);
	while (size != i / 2)
	{
		if (stack->b[0] >= mediane && size--)
			ft_pa(stack);
		else if (++swap)
			ft_rb(stack);
	}
	while (i / 2 != stack->size_b && swap--)
		ft_rrb(stack);
	return (ft_quicksort_a(stack, i / 2 + i % 2)
		&& ft_quicksort_b(stack, i / 2));
}