/* ************************************************************************** */
/*                                                                            */
/*   parser_array.c                                                           */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/14                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_size(char *array_char)
{
	char	**made_by_split;
	int		i;
	int		k;

	made_by_split = ft_split(array_char, ' ');
	if (!made_by_split)
		return (-404);
	i = ft_split_number(made_by_split);
	k = -1;
	while (made_by_split[++k])
		free(made_by_split[k]);
	free(made_by_split);
	return (i);
}

int	ft_split_number(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

static int	*ft_parser_array_int(char *array_char)
{
	char	**made_by_split;
	int		*array_int;
	int		i;
	int		j;
	int		k;

	made_by_split = ft_split(array_char, ' ');
	if (!made_by_split)
		return (NULL);
	i = ft_split_number(made_by_split);
	array_int = malloc(sizeof(int) * ft_split_number(made_by_split));
	if (!array_int)
		return (NULL);
	j = 0;
	k = 0;
	while (j < i)
		array_int[j++] = ft_atoi_push_swap(made_by_split[k++], \
		made_by_split, array_int);
	k = -1;
	while (made_by_split[++k])
		free(made_by_split[k]);
	free(made_by_split);
	return (array_int);
}

static char	*ft_parser_array_char(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strdup_push_swap(argv[1]);
	if (!str)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		tmp = ft_strjoin_push_swap(str, argv[i]);
		if (!tmp)
		{
			free(str);
			return (NULL);
		}
		free(str);
		str = tmp;
		i++;
	}
	return (str);
}

t_stack	ft_parser_array(int argc, char **argv)
{
	char	*array_char;
	int		*array_int;
	int		i;
	t_stack	stacks;

	ft_stacks_init(&stacks);
	array_char = ft_parser_array_char(argc, argv);
	if (!array_char)
		ft_error_memory(NULL, NULL, stacks);
	array_int = ft_parser_array_int(array_char);
	if (!array_int)
		ft_error_memory(array_char, NULL, stacks);
	i = ft_size(array_char);
	if (i == -404)
		ft_error_memory(array_char, array_int, stacks);
	free(array_char);
	ft_array_int_check(array_int, i);
	ft_array_sorted(array_int, i);
	stacks.a = malloc(sizeof(t_node));
	stacks.b = malloc(sizeof(t_node));
	if (!stacks.a || !stacks.b)
		ft_error_memory(array_char, array_int, stacks);
	ft_stacks_maker(stacks, array_int, i);
	return (stacks);
}
