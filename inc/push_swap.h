#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int *a;
    int *b;
    int size_a;
    int size_b;
}   t_stack;

//Moves
void    ft_sa(t_stack *stack)
void    ft_sb(t_stack *stack)
void    ft_ss(t_stack *stack)
void    ft_pa(t_stack *stack)
void    ft_pb(t_stack *stack)
void    ft_ra(t_stack *stack)
void    ft_rb(t_stack *stack)
void    ft_rr(t_stack *stack)
void    ft_rra(t_stack *stack)
void    ft_rrb(t_stack *stack)
void    ft_rrr(t_stack *stack)

#endif