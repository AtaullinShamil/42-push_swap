/* ************************************************************************** */
/*                                                                            */
/*   error.c                                                                  */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/18                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_memory(char *str, int *src, t_stack stacks)
{
	if (str)
		free(str);
	if (src)
		free(src);
	if (stacks.a->array)
		free(stacks.a->array);
	if (stacks.b->array)
		free(stacks.b->array);
	if (stacks.a)
		free(stacks.a);
	if (stacks.b)
		free(stacks.b);
	exit(-1);
}
