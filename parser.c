/* ************************************************************************** */
/*                                                                            */
/*   parser.c                                                                 */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/11                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit_push_swap(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static void	ft_mistake(void)
{
	write (1, "Error\n", 6);
	exit(-1);
}

static int	ft_checker(char c, char c_next)
{
	if (((ft_isdigit_push_swap(c) != 1) && (c != ' ') && (c != '-')) \
		|| ((c == '-') && (c_next == '-')) \
		|| ((c == ' ') && (c_next == ' ')) \
		|| ((c != ' ') && (c_next == '-')) \
		|| ((c == '-') && (ft_isdigit_push_swap(c_next) != 1)))
		return (0);
	else
		return (1);
}

static void	ft_parser_digital(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(-1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_checker(argv[i][j], argv[i][j + 1]) == 0)
				ft_mistake();
			j++;
		}
		i++;
	}
}

t_stack	ft_parser_body(int argc, char **argv)
{
	t_stack	stacks;

	ft_parser_digital(argc, argv);
	stacks = ft_parser_array(argc, argv);
	return (stacks);
}
