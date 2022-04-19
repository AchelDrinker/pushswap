/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_last_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:02:56 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/11 16:07:13 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_pa(int rotate, t_stacks *stk)
{
	rotate = true_minimaze_rotate(*stk->b, stk->max);
	while (rotate > 0)
	{
		ft_rb(&stk);
		rotate--;
	}
	while (rotate++ < 0)
		ft_rrb(&stk);
	while (*stk->b)
		ft_pa(&stk);
}

void	the_while(t_stacks *stk, int a, int *rotate)
{
	while (*stk->b && ft_lstsize(*stk->b) > 1)
	{
		if (*(int *)(*stk->b)->cont > a && *(int *)ft_lstlast(*stk->b)->cont
				> a)
		{
			if (*(int *)(*stk->b)->cont == ft_lstmaxint(*stk->b))
				break ;
			do_rb(rotate, stk);
		}
		else if (*(int *)(*stk->b)->cont < a
				&& *(int *)ft_lstlast(*stk->b)->cont < a)
		{
			if (*(int *)ft_lstlast(*stk->b)->cont == ft_lstminint(*stk->b))
				break ;
			do_rrb(rotate, stk);
		}
		else if (*(int *)(*stk->b)->cont > a
				&& *(int *)ft_lstlast(*stk->b)->cont < a)
		{
			opti_rotate_b(stk, a, rotate);
		}
		else
			break ;
	}
}

void	do_rb(int *rotate, t_stacks *stk)
{
	if (*rotate > 0)
	{
		ft_rr(&stk);
		(*rotate)--;
	}
	else
		ft_rb(&stk);
}

void	do_rrb(int *rotate, t_stacks *stk)
{
	if (*rotate < 0)
	{
		ft_rrr(&stk);
		(*rotate)++;
	}
	else
		ft_rrb(&stk);
}
