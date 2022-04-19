/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:14:42 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/14 14:12:02 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stacks **stk)
{
	t_list	**a_ptr;
	t_list	*a_next;

	if (*((*stk)->a) && (*((*stk)->a))->nx)
	{
		a_ptr = (*stk)->a;
		a_next = (*a_ptr)->nx;
		(*a_ptr)->nx = a_next->nx;
		a_next->nx = *a_ptr;
		*a_ptr = a_next;
	}
	ft_putendl_fd("sa", 1);
}
