/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:32:14 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/04 19:16:39 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

void	ra(t_swap *a, t_swap *b)
{
	int64_t	swp;
	int64_t	i;

	(void)b;
	if (a->len == 0)
		return ;
	i = a->len - 1;
	swp = a->stack[a->len - 1];
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = swp;
}

void	rb(t_swap *a, t_swap *b)
{
	int64_t	swp;
	int64_t	i;

	(void)a;
	if (b->len == 0)
		return ;
	i = b->len - 1;
	swp = b->stack[b->len - 1];
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = swp;
}

void	rr(t_swap *a, t_swap *b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_swap *a, t_swap *b)
{
	int64_t	swp;
	int64_t	i;

	(void)b;
	if (a->len == 0)
		return ;
	i = 0;
	swp = a->stack[0];
	while (i < a->len)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[a->len - 1] = swp;
}

void	rrb(t_swap *a, t_swap *b)
{
	int64_t	swp;
	int64_t	i;

	(void)b;
	if (b->len == 0)
		return ;
	i = 0;
	swp = b->stack[0];
	while (i < b->len)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->stack[b->len - 1] = swp;
}
