/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:08:12 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/08 19:35:14 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

/*
** Add a new index on the intex tab and increase his length
*/

int		add_index(t_part **s, size_t index)
{
	size_t	*new_tab;
	int		i;

	i = 0;	
	new_tab = (size_t *)malloc(sizeof(size_t) * ((*s)->len + 1));
	if (!new_tab)
		return (ft_error(MERR));
	if ((*s)->t_i != NULL)
	{
		while (i < (*s)->len)
		{
			new_tab[i] = (*s)->t_i[i];
			i++;
		}
		free((*s)->t_i);
	}
	new_tab[i] = index;
	(*s)->t_i = new_tab;
	(*s)->len = i + 1;
	return (0);
}

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


void	print_part(t_swap *s)
{
	int i;

	i = 0;
	while (i < s->part->len)
	{
		printf("Partition %d ==> |%zu|\n", i, s->part->t_i[i]);
		i++;
	}
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