/* ************************************************************************** */
/*                                                                            */
/*   sort.c                                                                   */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/16                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_go_to_b(t_stack stacks)
{
	int		min_a;
	int		max_a;
	int		mid;

	min_a = ft_lookfor_min(stacks);
	max_a = ft_lookfor_max(stacks);
	mid = ft_mean(stacks);
	while (stacks.a->array_size != 2)
	{
		if ((stacks.a->array[0] != min_a) && (stacks.a->array[0] != max_a))
		{
			if (stacks.b->array_size > 1 && stacks.a->array[0] > mid)
			{
				ft_pb(stacks);
				ft_rb(stacks);
			}
			else
				ft_pb(stacks);
		}
		else
			ft_ra(stacks);
	}
}

static void	ft_lets_back(t_stack stacks, int i)
{
	int	j;
	int	h;

	while (stacks.a->array_size != i + 1)
	{
		if (stacks.a->array[0] > stacks.b->array[0] \
			&& stacks.a->array[stacks.a->array_size - 1] < stacks.b->array[0])
			ft_pa(stacks);
		else
		{
			h = stacks.a->array_size;
			j = ft_get_index(stacks);
			if (j < h / 2)
				while (j--)
					ft_ra(stacks);
			else
			{
				j = (stacks.a->array_size - j);
				while (j--)
					ft_rra(stacks);
			}
		}
	}
}

static void	ft_finish(t_stack stacks)
{
	int	i;
	int	j;

	j = 0;
	i = ft_lookfor_min(stacks);
	while (stacks.a->array[j] != i)
		j++;
	if (j < stacks.a->array_size / 2)
		while (j--)
			ft_ra(stacks);
	else
	{
		j = (stacks.a->array_size - j);
		while (j--)
			ft_rra(stacks);
	}
}

static void	ft_sort_big(t_stack	stacks)
{
	int		i;
	int		j;

	i = stacks.a->array_size;
	stacks.b -> array = malloc(sizeof(int) * stacks.a->array_size);
	if (!stacks.b->array)
		ft_error_memory(NULL, NULL, stacks);
	ft_go_to_b(stacks);
	while (stacks.a->array_size != i)
	{
		j = stacks.a->array_size;
		ft_score(stacks);
		ft_lets_back(stacks, j);
	}
	ft_finish(stacks);
}

void	ft_sort_body(t_stack stacks)
{
	if (stacks.a -> array_size == 2)
		ft_sa(stacks);
	else if (stacks.a -> array_size == 3)
		ft_minisort_3(stacks);
	else if (stacks.a -> array_size == 5)
		ft_minisort_5(stacks);
	else
		ft_sort_big(stacks);
}
