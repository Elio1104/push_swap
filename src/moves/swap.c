/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:02:13 by alondot           #+#    #+#             */
/*   Updated: 2022/09/19 15:02:53 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack)
{
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_printf("sa\n");
}

void	ft_sb(t_stack *stack)
{
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	tmp = 0;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	ft_printf("sb\n");
}

void	ft_ss(t_stack *stack)
{
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1
		|| stack->size_a == 0 || stack->size_a == 1)
		return ;
	tmp = 0;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_printf("ss\n");
}
