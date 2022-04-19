/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trysort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:00:20 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/14 08:45:23 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	trysort3(t_stacks *stk);
static void	trysort5(t_stacks *stk);
static void	second_pa(t_stacks *stk);

void	trysort(t_stacks *stk)
{
	if (is_lstsorted(*(stk->a)))
		return ;
	else if (stk->size == 1)
		return ;
	else if (stk->size == 2)
	{
		if (!is_lstsorted(*stk->a))
			ft_sa(&stk);
	}
	else if (stk->size == 3)
		trysort3(stk);
	else if (stk->size == 5)
		trysort5(stk);
	else
		trysortmore(stk, stk->size);
}

static void	trysort3(t_stacks *stk)
{
	if (is_lstsorted(*(stk->a)))
		return ;
	if (*(int *)(*(stk->a))->cont > *(int *)(*(stk->a))->nx->cont)
	{
		if (*(int *)(*(stk->a))->nx->nx->cont > *(int *)(*(stk->a))->cont)
			ft_sa(&stk);
		else if (*(int *)(*(stk->a))->nx->nx->cont
			> *(int *)(*(stk->a))->nx->cont)
			ft_ra(&stk);
		else
		{
			ft_sa(&stk);
			ft_rra(&stk);
		}
	}
	else
	{
		if (*(int *)(*(stk->a))->cont > *(int *)(*(stk->a))->nx->nx->cont)
			ft_rra(&stk);
		else
		{
			ft_sa(&stk);
			ft_ra(&stk);
		}
	}
}

static void	trysort5(t_stacks *stk)
{
	if (is_lstsorted(*(stk->a)))
		return ;
	ft_pb(&stk);
	ft_pb(&stk);
	trysort3(stk);
	if (*(int *)(*stk->a)->nx->cont > *(int *)(*stk->b)->cont
		&& *(int *)(*stk->a)->cont < *(int *)(*stk->b)->cont)
		ft_ra(&stk);
	else if (*(int *)(*stk->a)->nx->nx->cont > *(int *)(*stk->b)->cont
		&& *(int *)(*stk->a)->nx->cont < *(int *)(*stk->b)->cont)
		ft_rra(&stk);
	ft_pa(&stk);
	second_pa(stk);
	ft_pa(&stk);
	while (*(int *)(*stk->a)->cont != stk->min)
	{
		ft_ra(&stk);
	}
}

static void	second_pa(t_stacks *stk)
{
	if ((*(int *)(*stk->a)->nx->cont > *(int *)(*stk->b)->cont
			&& *(int *)(*stk->a)->cont < *(int *)(*stk->b)->cont)
		|| (*(int *)(*stk->a)->cont == stk->max && *(int *)(*stk->a)->nx->cont
			> *(int *)(*stk->b)->cont) || (*(int *)(*stk->a)->cont
			< *(int *)(*stk->b)->cont && (*(int *)(*stk->a)->nx->cont
			== stk->min)))
		ft_ra(&stk);
	else if ((*(int *)(*stk->a)->nx->nx->cont > *(int *)(*stk->b)->cont
			&& *(int *)(*stk->a)->nx->cont < *(int *)(*stk->b)->cont)
			|| (*(int *)(*stk->a)->nx->cont == stk->max
			&& *(int *)(*stk->a)->nx->nx->cont > *(int *)(*stk->b)->cont)
		|| (*(int *)(*stk->a)->nx->cont < *(int *)(*stk->b)->cont
			&& (*(int *)(*stk->a)->nx->nx->cont == stk->min)))
	{
		ft_ra(&stk);
		ft_ra(&stk);
	}
	else if ((*(int *)(*stk->a)->nx->nx->nx->cont > *(int *)(*stk->b)->cont
			&& *(int *)(*stk->a)->nx->nx->cont < *(int *)(*stk->b)->cont)
		|| (*(int *)(*stk->a)->nx->nx->cont == stk->max
		&& *(int *)(*stk->a)->nx->nx->nx->cont
			> *(int *)(*stk->b)->cont) || (*(int *)(*stk->a)->nx->nx->cont
			< *(int *)(*stk->b)->cont && (*(int *)(*stk->a)->nx->nx->nx->cont
			== stk->min)))
		ft_rra(&stk);
}
