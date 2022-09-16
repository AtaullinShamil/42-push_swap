/* ************************************************************************** */
/*                                                                            */
/*   parser_array_helper.c                                                    */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/14                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stacks_init(t_stack *stacks)
{
	stacks -> a = NULL;
	stacks -> b = NULL;
}

void	ft_stacks_maker(t_stack stacks, int *str, int size)
{
	stacks.a -> array = str;
	stacks.a -> array_size = size;
	stacks.b -> array = NULL;
	stacks.b -> array_size = 0;
}

static void	ft_mistake_doubles(int *str)
{
	free(str);
	write (1, "Error\n", 6);
	exit(-1);
}

void	ft_array_int_check(int *str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (str[i] == str[j])
				ft_mistake_doubles(str);
			j++;
		}
		i++;
	}
}

void	ft_array_sorted(int *str, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (str[i + 1] < str[i])
			return ;
		i++;
	}
	exit (0);
}
