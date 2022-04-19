/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:14:40 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/14 14:12:15 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sb(t_stacks **stk)
{
	t_list	**b_ptr;
	t_list	*b_next;

	if (*((*stk)->b) && (*((*stk)->b))->nx)
	{
		b_ptr = (*stk)->b;
		b_next = (*b_ptr)->nx;
		(*b_ptr)->nx = b_next->nx;
		b_next->nx = *b_ptr;
		*b_ptr = b_next;
	}
	ft_putendl_fd("sb", 1);
}
