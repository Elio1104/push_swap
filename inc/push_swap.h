/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:54:33 by alondot           #+#    #+#             */
/*   Updated: 2022/09/12 13:58:45 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

# define TRUE 1
# define FALSE 0
# define ASCENDING 0
# define DESCENDING 1

//Moves
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);
//Utils
void	ft_error(int *stack);
int		ft_argv_atoi(char *str, int *stack);
int		ft_argv_strlen(char **argv);
void	ft_check_repeat(int *stack, int size);
int		ft_check_sorted(int *stack, int size, int order);
//Main
void	ft_push_swap(char **argv);
//Sorting
void	ft_sort_tmp(int *tmp_stack, int size);
void	ft_sort_3(t_stack *s);
void	ft_sorting(t_stack *stack, int size);
int		ft_push(t_stack *stack, int len, int operation);
void	ft_quicksort_3(t_stack *stack, int len);
int		ft_sort_small_b(t_stack *s, int len);
int		ft_get_mediane(int *mediane, int *stack, int size);
int		ft_quicksort_a(t_stack *stack, int size, int swap);
int		ft_quicksort_b(t_stack *stack, int size, int swap);

#endif
