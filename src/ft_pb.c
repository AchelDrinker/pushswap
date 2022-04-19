/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:14:50 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/10 13:58:15 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pb(t_stacks **stk)
{
	t_list	**a_ptr;
	t_list	**b_ptr;
	t_list	*a;

	if (*((*stk)->a) && (*stk)->b)
	{
		a_ptr = (*stk)->a;
		b_ptr = (*stk)->b;
		a = *((*stk)->a);
		*a_ptr = a->nx;
		a->nx = *b_ptr;
		*b_ptr = a;
	}
	ft_putendl_fd("pb", 1);
}
