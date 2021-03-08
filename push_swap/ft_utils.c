/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:08:12 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/07 21:20:22 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"


// Attention printf

void	sort_tab(int64_t* tab, int64_t size)
{
	int sort;
	int i;

	sort = 0;
	while (sort == 0)
	{
		sort = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap(&tab[i], &tab[i + 1]);
				sort = 0;
			}
			i++;
		}
	}
}

int	getMedian(int64_t *stack, int64_t start, int64_t end, int64_t *med)
{
	int64_t *tab;
	int64_t	i;
	int64_t len;

	len = end - start;
	if (end == 0)
		return (0);
	if (!(tab = (int64_t*)malloc(sizeof(int64_t) * len)))
		return (ft_error(MERR));
	i = 0;
	while (i < len)
	{
		tab[i] = stack[start];
		i++;
		start++;
	}
	sort_tab(tab, len);
	/*for (int i = 0; i < len; i++)  // virer
		printf("i -> |%ld|\n", tab[i]);*/
	*med = tab[((len + 1) / 2) - 1];
	free(tab);
	return (0);
}

void	swap(int64_t *n1, int64_t *n2)
{
	int64_t swp;

	swp = *n1;
	*n1 = *n2;
	*n2 = swp;
}

void	print_stack(t_swap *s)
{
	int i;
	i = s->len;
	while (i > 0)
	{
		ft_putstr_fd("> ", 1);
		ft_putnbr_fd(s->stack[i - 1], 1);
		ft_putchar_fd('\n', 1);
		i--;
	}
	ft_putstr_fd("|-------------------\n", 1);

}