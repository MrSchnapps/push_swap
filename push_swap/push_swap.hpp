/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:27:56 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/04 22:20:48 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define NAN 3
# define MERR 4
# define DERR 5

typedef struct	s_swap 
{
	int64_t*	stack;
	size_t		size;
	size_t		len;	
}				t_swap;

/*
** Free - Errors
*/

int		ft_free(t_swap *a, t_swap *b, int code);
int		ft_error(int code);

/*
** Lib
*/

int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strcmp(char *s1, char *s2);

/*
** Utils
*/

void	print_stack(t_swap *s);
void	swap(int64_t *n1, int64_t *n2);
int64_t	getMedian(int64_t *stack, int64_t start, int64_t end);

/*
** Operations
*/

void	sa(t_swap *a, t_swap *b);
void	sb(t_swap *a, t_swap *b);
void	ss(t_swap *a, t_swap *b);
void	pa(t_swap *a, t_swap *b);
void	pb(t_swap *a, t_swap *b);
void	ra(t_swap *a, t_swap *b);
void	rb(t_swap *a, t_swap *b);
void	rr(t_swap *a, t_swap *b);
void	rra(t_swap *a, t_swap *b);
void	rrb(t_swap *a, t_swap *b);
void	rrr(t_swap *a, t_swap *b);
void	rrr(t_swap *a, t_swap *b);

#endif