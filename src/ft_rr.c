/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:14:48 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/09 13:26:29 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rr(t_stacks **stk)
{
	t_list	**b_ptr;
	t_list	*b_next;
	t_list	**a_ptr;
	t_list	*a_next;

	if (ft_lstsize(*((*stk)->a)))
	{
		a_ptr = (*stk)->a;
		a_next = (*a_ptr)->nx;
		ft_lstlast(*a_ptr)->nx = *a_ptr;
		(*a_ptr)->nx = NULL;
		*a_ptr = a_next;
	}
	if (ft_lstsize(*((*stk)->b)))
	{
		b_ptr = (*stk)->b;
		b_next = (*b_ptr)->nx;
		ft_lstlast(*b_ptr)->nx = *b_ptr;
		(*b_ptr)->nx = NULL;
		*b_ptr = b_next;
	}
	ft_putendl_fd("rr", 1);
}

void	ft_rrr(t_stacks **stk)
{
	t_list	**b_ptr;
	t_list	*b_last;
	t_list	**a_ptr;
	t_list	*a_last;

	if (ft_lstsize(*((*stk)->b)) > 1)
	{
		b_ptr = (*stk)->b;
		b_last = ft_lstlast(*b_ptr);
		ft_lstcalendar(*b_ptr, ft_lstsize(*b_ptr) - 2)->nx = NULL;
		b_last->nx = *b_ptr;
		*b_ptr = b_last;
	}
	if (ft_lstsize(*((*stk)->a)) > 1)
	{
		a_ptr = (*stk)->a;
		a_last = ft_lstlast(*a_ptr);
		ft_lstcalendar(*a_ptr, ft_lstsize(*a_ptr) - 2)->nx = NULL;
		a_last->nx = *a_ptr;
		*a_ptr = a_last;
	}
	ft_putendl_fd("rrr", 1);
}
