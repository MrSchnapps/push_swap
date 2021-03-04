/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:30:46 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/04 19:18:43 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

void	sa(t_swap *a, t_swap *b)
{
	(void)b;
	if (a->len >= 2)
		swap(&a->stack[a->len-1], &a->stack[a->len-2]);
}

void	sb(t_swap *a, t_swap *b)
{
	(void)a;
	if (b->len >= 2)
		swap(&b->stack[b->len-1], &b->stack[b->len-2]);
}

void	ss(t_swap *a, t_swap *b)
{
	if (a->len >= 2)
		swap(&a->stack[a->len-1], &a->stack[a->len-2]);
	if (b->len >= 2)
		swap(&b->stack[b->len-1], &b->stack[b->len-2]);
}

void	pa(t_swap *a, t_swap *b)
{
	if (b->len > 0)
	{
		if (a->len < a->size)
		{
			a->stack[a->len] = b->stack[b->len - 1];
			a->len += 1;
			b->len -= 1;
		}
	}
}

void	pb(t_swap *a, t_swap *b)
{
	if (a->len > 0)
	{
		if (b->len < b->size)
		{
			b->stack[b->len] = a->stack[a->len - 1];
			b->len += 1;
			a->len -= 1;
		}
	}
}
