/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:55:15 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/05 00:04:01 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

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
	int sorted;

	sorted = 0;
}