void    ft_rra(t_stack *stack)
{
    int tmp;
    int i;
    
    if(stack->size_a == 0 || stack->size_a == 1)
        return;
    i = stack->size_a;
    tmp = stack->a[i - 1];
    while (--i > 0)
        stack->a[i] = stack->a[i - 1];
    stack->a[i] = tmp;
    ft_printf("rra\n");
}

void    ft_rrb(t_stack *stack)
{
    int tmp;
    int i;
    
    if(stack->size_b == 0 || stack->size_b == 1)
        return;
    i = stack->size_b;
    tmp = stack->b[i - 1];
    while (--i > 0)
        stack->b[i] = stack->b[i - 1];
    stack->b[i] = tmp;
    ft_printf("rrb\n");
}

void    ft_rrr(t_stack *stack)
{
    int tmp;
    int i;
    
    if(stack->size_a == 0 || stack->size_a == 1
        || stack->size_b == 0 || stack->size_b == 1)
        return;
    i = stack->size_a;
    tmp = stack->a[i - 1];
    while (--i > 0)
        stack->a[i] = stack->a[i - 1];
    stack->a[i] = tmp;
    i = stack->size_b;
    tmp = stack->b[i - 1];
    while (--i > 0)
        stack->b[i] = stack->b[i - 1];
    stack->b[i] = tmp;
    ft_printf("rrr\n");
}