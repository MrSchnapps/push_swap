/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:27:22 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/04 22:46:05 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

/*
** First parsing is an argument isn't a number return a error code (NAN) else return 0
*/

int	allocate_stack(t_swap *a, t_swap *b, char **argv, int argc)
{
	int i;
	int j;

	i = argc - 1;
	j = 0;
	if (!(a->stack = (int64_t *)malloc(sizeof(int64_t) * i)))
		return (ft_error(MERR));
	if (!(b->stack = (int64_t *)malloc(sizeof(int64_t) * i)))
		return (ft_error(ft_free(a, b, MERR)));
	while (i > 0)
	{
		a->stack[j] = ft_atoi(argv[i]);
		a->len++;
		j++;
		i--;
	}
	i = -1;
	while (++i < a->len - 1)
	{
		j = i;
		while (++j < a->len)
			if (a->stack[i] == a->stack[j])
				return (ft_error(ft_free(a, b, DERR)));
	}
	return (0);
}

int	parse_args(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '\t' || argv[i][j] == '\n'
				|| argv[i][j] == '\r' || argv[i][j] == '\v' || argv[i][j] == '\f')
			j++;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j += 1;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (ft_error(NAN));
			j++;
		}
		i++;
	}
	return (0);
}

void init(t_swap *sa, t_swap *sb, int argc)
{
	sa->size = argc - 1;
	sb->size = argc - 1;
	sa->stack = NULL;
	sb->stack = NULL;
	sa->len = 0;
	sb->len = 0;
}

int main(int argc, char **argv)
{
	t_swap	a;
	t_swap	b;
	int64_t	err;
	int64_t	moy;

	if (argc < 2)
		return (0);
	init(&a, &b, argc);
	if ((err = parse_args(argv)))
		return (err);
	if ((err = allocate_stack(&a, &b, argv, argc)))
		return (err);

	//tests
	if ((err = getMedian(a.stack, 0, a.len, moy))
		return (ft_free(&a, &b, err));
	printf("\nmediane => |%ld|", moy);
	//free final
	ft_free(&a, &b, 0);
	return (0);
}