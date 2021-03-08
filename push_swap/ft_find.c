/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:55:15 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/08 01:13:08 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"
#include <time.h>

/*void	check_median(t_swap *a, t_swap *b)
{
	int i;
	
	i = a->len;
	while(i >= 0)
	{
		if ()
	}
}*/

void	sort_three(t_swap *a, t_swap *b)
{
	printf("\nOn Split\n");
	int is_push;

	is_push = 0;
	if (a->len <= 1)
		return ;
	else if (a->len == 2)
	{
		if (a->stack[a->len - 1] > a->stack[a->len - 2])
		{
			sa(a, b);
			return ;
		}
	}
	else
	{
		while (a->stack[a->len - 2] < a->stack[a->len - 1] || a->stack[a->len - 2] > a->stack[a->len - 3])
		{
			if (a->stack[a->len - 1] > a->stack[a->len - 2])
				sa(a, b);
			if (a->stack[a->len - 2] > a->stack[a ->len - 3] && a->len > 2)
			{
				pb(a, b);
				is_push += 1;
			}
			if (a->stack[a->len - 1] < a->stack[a ->len - 2] && is_push > 0)
			{
				pa(a, b);
				is_push -= 1;
			}
		}
	}
}

void	split_a(t_swap *a, t_swap *b)
{
	int64_t median;
	size_t	i;

	getMedian(a->stack, 0, a->len, &median);
	i = 0;
	printf("\nmediane => |%ld|\n", median);
	while (i < a->len)
	{
		if (a->stack[a->len - 1] <= median && a->len > 3)
			pb(a, b);
		ra(a, b);
		i++;
	}
}

/*
** Return 1 if the list is sorted or 0 if not
*/

int		check_sorted(t_swap *s)
{
	int64_t i;

	i = s->len;
	if (s->len != s->size)
		return (0);
	while (i > 0)
	{
		if (s->stack[i] > s->stack[i - 1])
			return (0);
		i--;	
	}
	return (1);
}

void	ft_find(t_swap *a, t_swap *b)
{
	//while (!check_sorted(a))
	//{
		while (a->len > 3)
			split_a(a, b);
		
		printf("\nAVANT SORT THREE\n");
		printf("Stack a : \n");
		print_stack(a);
		printf("Stack b : \n");
		print_stack(b);
		printf("======================");
		
		sort_three(a, b); 
	//}
}