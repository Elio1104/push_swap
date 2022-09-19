/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:43:02 by alondot           #+#    #+#             */
/*   Updated: 2022/09/19 14:50:46 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quicksort_3(t_stack *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ft_sort_3(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (len++)
				ft_pa(stack);
		}
	}
}

int	ft_sort_small_b(t_stack *s, int len)
{
	if (len == 1)
		ft_pa(s);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			ft_sb(s);
		while (len--)
			ft_pa(s);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				ft_sa(s);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ft_push(s, len, 1);
			else
				ft_sb(s);
		}
	}
	return (0);
}

int	ft_get_mediane(int *mediane, int *stack, int size)
{
	int	*tmp_stack;
	int	i;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	ft_sort_tmp(tmp_stack, size);
	*mediane = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

int	ft_quicksort_a(t_stack *stack, int size, int swap)
{
	int	mediane;
	int	i;

	if (ft_check_sorted(stack->a, size, ASCENDING) == TRUE)
		return (1);
	i = size;
	if (size <= 3)
	{
		ft_quicksort_3(stack, size);
		return (1);
	}
	if (!ft_get_mediane(&mediane, stack->a, size))
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
	return (ft_quicksort_a(stack, i / 2 + i % 2, 0)
		&& ft_quicksort_b(stack, i / 2, 0));
	return (1);
}

int	ft_quicksort_b(t_stack *stack, int size, int swap)
{
	int	mediane;
	int	i;

	if (ft_check_sorted(stack->b, size, DESCENDING) == 1)
		while (size--)
			ft_pa(stack);
	if (size <= 3)
	{
		ft_sort_small_b(stack, size);
		return (1);
	}
	i = size;
	if (!ft_get_mediane(&mediane, stack->b, size))
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
	return (ft_quicksort_a(stack, i / 2 + i % 2, 0)
		&& ft_quicksort_b(stack, i / 2, 0));
}
