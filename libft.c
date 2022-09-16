/* ************************************************************************** */
/*                                                                            */
/*   libft.c                                                                  */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/02/14                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen_push_swap(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_push_swap(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_push_swap(s1) + ft_strlen_push_swap(s2);
	str = (char *)malloc(sizeof(*s1) * (len + 2));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = ' ';
	str[i + 1] = '\0';
	return (str);
}

char	*ft_strdup_push_swap(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen_push_swap(s1) + 2));
	if (!str)
		return (NULL);
	else
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = ' ';
		str[i + 1] = '\0';
		return (str);
	}
}

static void	ft_mistake(char **made_by_split, int *array_int)
{
	int	k;

	write (1, "Error\n", 6);
	k = -1;
	while (made_by_split[++k])
		free(made_by_split[k]);
	free(made_by_split);
	free(array_int);
	exit(-1);
}

int	ft_atoi_push_swap(const char *str, char **made_by_split, int *array_int)
{
	int			i;
	long int	negative;
	long int	res;

	negative = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			||str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = -1;
	if (negative == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res * negative <= -2147483649)
			ft_mistake(made_by_split, array_int);
		else if (res * negative >= 2147483648)
			ft_mistake(made_by_split, array_int);
		i++;
	}
	return (res * negative);
}
