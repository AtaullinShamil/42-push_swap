/* ************************************************************************** */
/*                                                                            */
/*   rules_1.c                                                                */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/16                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack stacks)
{
	int	i;

	i = stacks.b->array_size;
	while (i > 0)
	{
		stacks.b->array[i] = stacks.b->array[i - 1];
		i--;
	}
	stacks.b->array[0] = stacks.a->array[0];
	i = 0;
	while (i < stacks.a->array_size)
	{
		stacks.a->array[i] = stacks.a->array[i + 1];
		i++;
	}
	stacks.a->array_size--;
	stacks.b->array_size++;
	write(1, "pb\n", 3);
}

void	ft_pa(t_stack stacks)
{
	int	i;

	i = stacks.a->array_size;
	while (i > 0)
	{
		stacks.a->array[i] = stacks.a->array[i - 1];
		i--;
	}
	stacks.a->array[0] = stacks.b->array[0];
	i = 0;
	while (i < stacks.b->array_size)
	{
		stacks.b->array[i] = stacks.b->array[i + 1];
		i++;
	}
	stacks.b->array_size--;
	stacks.a->array_size++;
	write(1, "pa\n", 3);
}

void	ft_ra(t_stack stacks)
{
	int	i;
	int	j;

	i = 0;
	j = stacks.a->array[0];
	while (i < stacks.a->array_size - 1)
	{
		stacks.a->array[i] = stacks.a->array[i + 1];
		i++;
	}
	stacks.a->array[stacks.a->array_size - 1] = j;
	write(1, "ra\n", 3);
}

void	ft_rra(t_stack stacks)
{
	int	i;
	int	j;

	i = stacks.a->array_size - 1;
	j = stacks.a->array[stacks.a->array_size - 1];
	while (i > 0)
	{
		stacks.a->array[i] = stacks.a->array[i - 1];
		i--;
	}
	stacks.a->array[0] = j;
	write(1, "rra\n", 4);
}

void	ft_sa(t_stack stacks)
{
	int	i;

	i = stacks.a->array[0];
	stacks.a->array[0] = stacks.a->array[1];
	stacks.a->array[1] = i;
	write(1, "sa\n", 3);
}
