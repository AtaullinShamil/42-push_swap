/* ************************************************************************** */
/*                                                                            */
/*   sort_mean.c                                                              */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/22                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sorting(int *str, int size_array)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < size_array - 1)
	{
		j = size_array - 1;
		while (j > i)
		{
			if (str[j - 1] > str[j])
			{
				t = str[j - 1];
				str[j - 1] = str[j];
				str[j] = t;
			}
			j--;
		}
		i++;
	}
}

int	ft_mean(t_stack stacks)
{
	int	*str;
	int	i;
	int	j;

	str = malloc(sizeof(int) * stacks.a->array_size);
	if (!str)
		ft_error_memory(NULL, NULL, stacks);
	i = 0;
	while (i < stacks.a->array_size)
	{
		str[i] = stacks.a->array[i];
		i++;
	}
	ft_sorting(str, stacks.a->array_size);
	if (stacks.a->array_size % 2 != 0)
		j = str[stacks.a->array_size / 2];
	else
		j = (str[stacks.a->array_size / 2] + \
		str[(stacks.a->array_size / 2) - 1]) / 2;
	free(str);
	return (j);
}
