/* ************************************************************************** */
/*                                                                            */
/*   sort_score.c                                                             */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/21                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_b_ready(t_stack stacks, int j)
{
	if (j < stacks.b->array_size / 2)
		while (j--)
			ft_rb(stacks);
	else
	{
		j = stacks.b->array_size - j;
		while (j--)
			ft_rrb(stacks);
	}
}

void	ft_score(t_stack stacks)
{
	int	i;
	int	score;
	int	minimal_score;
	int	position;

	i = 0;
	minimal_score = 2147483647;
	while (i < stacks.b->array_size)
	{
		if (i < stacks.b->array_size / 2)
			score = i + ft_get_index_score(stacks, i);
		else
			score = stacks.b->array_size - i + ft_get_index_score(stacks, i);
		if (score < minimal_score)
		{
			minimal_score = score;
			position = i;
		}
		i++;
	}
	ft_b_ready(stacks, position);
}
