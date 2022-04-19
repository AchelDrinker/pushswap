/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:57:48 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/09 13:26:29 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ss(t_stacks **stk)
{
	t_list	**a_ptr;
	t_list	*a_next;
	t_list	**b_ptr;
	t_list	*b_next;

	b_ptr = (*stk)->b;
	b_next = (*b_ptr)->nx;
	(*b_ptr)->nx = b_next->nx;
	b_next->nx = *b_ptr;
	*b_ptr = b_next;
	a_ptr = (*stk)->a;
	a_next = (*a_ptr)->nx;
	(*a_ptr)->nx = a_next->nx;
	a_next->nx = *a_ptr;
	*a_ptr = a_next;
	ft_putendl_fd("ss", 1);
}
