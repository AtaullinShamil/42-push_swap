/* ************************************************************************** */
/*                                                                            */
/*   push_swap.c                                                              */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/11                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;

	stacks = ft_parser_body(argc, argv);
	ft_sort_body(stacks);
	free(stacks.a->array);
	free(stacks.b->array);
	free(stacks.a);
	free(stacks.b);
	return (0);
}
