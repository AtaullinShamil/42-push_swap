/* ************************************************************************** */
/*                                                                            */
/*   rules_2.c                                                                */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/17                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_stack stacks)
{
	int	i;
	int	j;

	i = 0;
	j = stacks.b->array[0];
	while (i < stacks.b->array_size - 1)
	{
		stacks.b->array[i] = stacks.b->array[i + 1];
		i++;
	}
	stacks.b->array[stacks.b->array_size - 1] = j;
	write(1, "rb\n", 3);
}

void	ft_rrb(t_stack stacks)
{
	int	i;
	int	j;

	i = stacks.b->array_size - 1;
	j = stacks.b->array[stacks.b->array_size - 1];
	while (i > 0)
	{
		stacks.b->array[i] = stacks.b->array[i - 1];
		i--;
	}
	stacks.b->array[0] = j;
	write(1, "rrb\n", 4);
}

void	ft_rr(t_stack stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	write(1, "rrr\n", 4);
}

void	ft_sb(t_stack stacks)
{
	int	i;

	i = stacks.b->array[0];
	stacks.b->array[0] = stacks.b->array[1];
	stacks.b->array[1] = i;
	write(1, "sb\n", 3);
}
