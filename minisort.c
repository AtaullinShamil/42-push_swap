/* ************************************************************************** */
/*                                                                            */
/*   minisort.c                                                               */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/23                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_minisort_3(t_stack stacks)
{
	int		min_a;
	int		max_a;
	int		mid;

	min_a = ft_lookfor_min(stacks);
	max_a = ft_lookfor_max(stacks);
	mid = ft_mean(stacks);
	if (stacks.a->array[0] == mid && stacks.a->array[2] == min_a)
		ft_rra(stacks);
	else if (stacks.a->array[2] == mid && stacks.a->array[1] == min_a)
		ft_ra(stacks);
	if (ft_isitready(stacks) == 1)
		return ;
	ft_sa(stacks);
	if (ft_isitready(stacks) == 1)
		return ;
	if (stacks.a->array[0] == max_a)
		ft_ra(stacks);
	else
		ft_rra(stacks);
	if (ft_isitready(stacks) == 1)
		return ;
}

void	ft_minisort_5(t_stack stacks)
{
	int		mid;

	mid = ft_mean(stacks);
	stacks.b -> array = malloc(sizeof(int) * stacks.a->array_size);
	if (!stacks.b->array)
		ft_error_memory(NULL, NULL, stacks);
	while (stacks.a->array_size > 3)
	{
		if (stacks.a->array[0] < mid)
			ft_pb(stacks);
		else
			ft_ra(stacks);
	}
	ft_minisort_3(stacks);
	if (stacks.b->array_size > 1 && stacks.b->array[0] < stacks.b->array[1])
		ft_rb(stacks);
	ft_pa(stacks);
	ft_pa(stacks);
}
