/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:45:39 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/07 14:02:21 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/push_swap.hpp"

void	lst_pop(t_part **lst)
{
	t_part *tmp;
	t_part *ret;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	if (!tmp->next)
	{
		*lst = NULL;
		free(tmp);
		return ;
	}
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	ret = tmp->next;
	tmp->next = NULL;
	if (ret)
		free(ret);
}

t_part	*lst_last(t_part *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_part	*lst_new_prt(int index)
{
	t_part *new;

	new = (t_part *)malloc(sizeof(t_part));
	if (!new || index < 0)
		return (NULL);
	new->index = index;
	new->next = NULL;
	return (new);
}

int	lst_add_prt(t_part **prt, int index)
{
	t_part *new;

	if (!prt)
		return (0);
	if (index < 0)
		return (ft_error(INDERR));
	new = lst_new_prt(index);
	if (!new)
		return (ft_error(MERR));
	if (!*prt)
		*prt = new;
	else
		lst_last(*prt)->next = new;
	return (0);
}

void	print_lst(t_part *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("List part -> |%d|\n", lst->index);
		lst = lst->next;
	}
}

// a virer
/*int main()
{
	int i = 5;
	int size = 0;

	t_part *partition = NULL;
	while (size < i)
	{
		lst_add_prt(&partition, size);
		size++;
	}
	print_lst(partition);
	lst_pop(&partition);
	print_lst(partition);
	lst_pop(&partition);
	print_lst(partition);
	lst_pop(&partition);
	print_lst(partition);
	lst_pop(&partition);
	print_lst(partition);
	lst_pop(&partition);
	print_lst(partition);
	for (int z = 0; z < 5; z++)
	{
		lst_pop(&partition);
	}
	return (0);
	
}*/