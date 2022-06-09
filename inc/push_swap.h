#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int *a;
    int *b;
    int size_a;
    int size_b;
}   t_stack;

# define TRUE 1
# define FALSE 0

//Moves
void    ft_sa(t_stack *stack);
void    ft_sb(t_stack *stack);
void    ft_ss(t_stack *stack);
void    ft_pa(t_stack *stack);
void    ft_pb(t_stack *stack);
void    ft_ra(t_stack *stack);
void    ft_rb(t_stack *stack);
void    ft_rr(t_stack *stack);
void    ft_rra(t_stack *stack);
void    ft_rrb(t_stack *stack);
void    ft_rrr(t_stack *stack);

//Utils
void	ft_error(int *stack);
int     ft_argv_atoi(char *str, int *stack);
int		ft_argv_strlen(char **argv);
int		ft_check_repeat(int *stack, int size);
int		ft_check_sorted(int *stack, int size);

#endif