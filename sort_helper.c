/* ************************************************************************** */
/*                                                                            */
/*   sort_helper.c                                                            */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/16                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isitready(t_stack stacks)
{
	int	i;

	i = 1;
	while (i < stacks.a -> array_size)
	{
		if (stacks.a -> array[i - 1] > stacks.a -> array[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_lookfor_min(t_stack stacks)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (i < (stacks.a -> array_size))
	{
		if (stacks.a -> array[i] < min)
			min = stacks.a -> array[i];
		i++;
	}
	return (min);
}

int	ft_lookfor_max(t_stack stacks)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483648;
	while (i < (stacks.a -> array_size))
	{
		if (stacks.a -> array[i] > max)
			max = stacks.a -> array[i];
		i++;
	}
	return (max);
}

int	ft_get_index(t_stack stacks)
{
	int	i;

	i = 1;
	while (!(stacks.a->array[i] > stacks.b->array[0] \
			&& stacks.a->array[i - 1] < stacks.b->array[0]))
		i++;
	return (i);
}

int	ft_get_index_score(t_stack stacks, int j)
{
	int	i;

	i = 0;
	while (i < stacks.a->array_size)
	{
		if (i < 1)
		{
			if (stacks.a->array[0] > stacks.b->array[j] && \
			stacks.a->array[stacks.a->array_size - 1] < stacks.b->array[j])
				return (i);
		}
		else
		{
			if (stacks.a->array[i] > stacks.b->array[j] \
					&& stacks.a->array[i - 1] < stacks.b->array[j])
				return (i);
		}
		i++;
	}
	return (2147483647);
}
