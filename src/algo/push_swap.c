#include "push_swap.h"

void	ft_push_swap(char **argv)
{
    t_stack stack;
	int     size;
	int     i;

	i = -1;
	size = ft_argv_strlen(argv);
	stack.a = malloc(size * sizeof(int));
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(size * sizeof(int));
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++i < size)
		stack.a[i] = ft_argv_atoi(argv[i], stack.a);
    if (ft_check_repeat(stack.a, size) == FALSE)
		ft_sorting(&stack, size);
	free(stack.a);
	free(stack.b);
}


int		main(int argc, char **argv)
{
    if (argc > 1)
    {
        argv++;
        if (argc == 2)
            argv = ft_split(*argv, ' ');
        ft_push_swap(argv);
    }
    return (0);
}