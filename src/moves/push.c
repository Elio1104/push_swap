void    ft_pa(t_stack *stack)
{
    int i;

    if(!stack->size_b)
        return;
    stack->size_a++;
    i = stack->size_a;
    while (--i > 0)
        stack->a[i] = stack->a[i - 1];
    stack->a[0] = stack->b[0];
    stack->size_b--;
    i = -1;
    while (++i < stack->size_b)
        stack->b[i] = stack->b[i + 1];
    ft_printf("pa\n");
}

void    ft_pb(t_stack *stack)
{
    int i;

    if(!stack->size_a)
        return;
    stack->size_b++;
    i = stack->size_b;
    while (--i > 0)
        stack->b[i] = stack->b[i - 1];
    stack->b[0] = stack->a[0];
    stack->size_a--;
    i = -1;
    while (++i < stack->size_a)
        stack->a[i] = stack->a[i + 1];
    ft_printf("pb\n");
}