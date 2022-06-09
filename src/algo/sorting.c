#include "push_swap.h"

void    ft_sort_3(t_stack *s)
{
    if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		ft_sa(s);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		ft_sa(s);
		ft_rra(s);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ft_ra(s);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		ft_sa(s);
		ft_ra(s);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		ft_rra(s);
}

void	ft_sorting(t_stack *stack, int size)
{
	if(ft_check_sorted(stack->a, stack->size_a) == 0)
	{
		if (size == 2)
			ft_sa(stack);
		if (size == 3)
			ft_sort_3(stack);
		else
			ft_big_sort(stack, size);
	}
	return (0);
}