/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:55:15 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/08 20:45:46 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"
#include <time.h> //virer time

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
	//printf("\nOn Sort three\n");
	int is_push;

	is_push = 0;
	if (a->len <= 1)
		return ;
	else if (a->len - a->part->len == 2)
	{
		if (a->stack[a->len - 1] > a->stack[a->len - 2])
			sa(a, b);
	}
	else
	{
		while (a->stack[a->len - 2] < a->stack[a->len - 1] || a->stack[a->len - 2] > a->stack[a->len - 3])
		{
			if (a->stack[a->len - 1] > a->stack[a->len - 2])
			{
				sa(a, b);
			}
			if (a->len > 2 && a->stack[a->len - 2] > a->stack[a ->len - 3])
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
	a->part->len = a->len;
}

void	b_to_a(t_swap *a, t_swap *b)
{
	int i;
	int max;

	i = -1;
	if (b->part->len == 0)
		return ;
	else if (b->part->len == 1)
		while ((size_t)++i <= b->part->t_i[0])
			pa(a, b);
	else
	{
		max = (int)(b->part->t_i[b->part->len - 1] - b->part->t_i[b->part->len - 2]);
		while (++i < max)
			pa(a, b);
		if (max > 3)
			a->part->len = a->len - (max + 1);
	}
	b->part->len -= 1;
}

/*
** Calculate the median of A and push all the numbers <= median to B
*/

int		split_a(t_swap *a, t_swap *b)
{
	int64_t median;
	size_t	i;
	size_t	min;
	int		rot;

	rot = 0;
	min = a->part->len;
	getMedian(a->stack, min, a->len, &median);
	i = (int)(a->len - min);
	//printf("\nmediane => |%ld|\n", median);
	while (i > 0)
	{
		//printf("stack len - 1 --- |%ld|\n", a->stack[a->len - 1]);
		//printf("stack len--- |%zu|\n",a->len);
		if (a->stack[a->len - 1] <= median)
			pb(a, b);
		else
		{
			ra(a, b);
			rot++;
		}
		i--;
	}
	if (b->len > 0)
		if (add_index(&b->part, b->len - 1))
			return (MERR);
	if (a->part->len != 0 && rot > 0)
		while (rot--)
			rra(a, b);
	return (0);
}

/*
** Return 1 if the list is sorted or 0 if not
*/

int		check_sorted(t_swap *s)
{
	size_t i;

	i = s->len - 1;
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

int		ft_find(t_swap *a, t_swap *b)
{
	while (!check_sorted(a))
	{
		while (a->len - a->part->len > 3)
			if (split_a(a, b))
				return (MERR);
		/*printf("\nAVANT SORT THREE\n");
		printf("Stack a : \n");
		print_stack(a);
		printf("Stack b : \n");
		print_stack(b);
		printf("======================\n");*/
		
		//print_part(b);
		sort_three(a, b);
		b_to_a(a, b);
		/*split_a(a, b);
		//printf("part len --> |%d|\n", a->part->len);
		b_to_a(a, b);
		printf("part len --> |%d|\n", a->part->len);
		split_a(a, b);*/
	}
	return (0);
}