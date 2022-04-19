/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:14:52 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/09 13:26:29 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_stacks **stk)
{
	t_list	**b_ptr;
	t_list	**a_ptr;
	t_list	*b;

	if (*((*stk)->b))
	{
		b_ptr = (*stk)->b;
		a_ptr = (*stk)->a;
		b = *((*stk)->b);
		*b_ptr = b->nx;
		b->nx = *a_ptr;
		*a_ptr = b;
	}
	ft_putendl_fd("pa", 1);
}
