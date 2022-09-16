/* ************************************************************************** */
/*                                                                            */
/*   push_swap.h                                                              */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/11                                                      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "stdio.h"

typedef struct s_node
{
	int	*array;
	int	array_size;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

t_stack	ft_parser_body(int argc, char **argv);
t_stack	ft_parser_array(int argc, char **argv);
int		ft_split_number(char **str);
void	ft_array_int_check(int *str, int size);
void	ft_array_sorted(int *str, int size);
void	ft_stacks_maker(t_stack stacks, int *str, int size);
void	ft_stacks_init(t_stack *stacks);

char	*ft_strdup_push_swap(const char *s1);
char	*ft_strjoin_push_swap(char const *s1, char const *s2);
int		ft_atoi_push_swap(const char *str, char **made_by_split, \
		int *array_int);
char	**ft_split(char const *s, char c);

void	ft_sort_body(t_stack stacks);
void	ft_minisort_3(t_stack stacks);
void	ft_minisort_5(t_stack stacks);
int		ft_lookfor_max(t_stack stacks);
int		ft_lookfor_min(t_stack stacks);
int		ft_mean(t_stack stacks);
int		ft_isitready(t_stack stacks);
int		ft_get_index(t_stack stacks);
int		ft_get_index_score(t_stack stacks, int j);
void	ft_score(t_stack stacks);

void	ft_pb(t_stack stacks);
void	ft_ra(t_stack stacks);
void	ft_pa(t_stack stacks);
void	ft_rra(t_stack stacks);
void	ft_rb(t_stack stacks);
void	ft_rrb(t_stack stacks);
void	ft_rr(t_stack stacks);
void	ft_rrr(t_stack stacks);
void	ft_sa(t_stack stacks);
void	ft_sb(t_stack stacks);

void	ft_error_memory(char *str, int *src, t_stack stacks);

#endif
