/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trysortparttwo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:39:06 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/11 16:06:37 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	*get_chunk(int *arr, int size, int nb_chk, int i);
static int	set_rotate(t_stacks *stk, int nb_chk, int i, int *rotate);

void	trysortmore(t_stacks *stk, size_t size)
{
	t_trysort	trysort;

	trysort.nb_chk = closest_divisor(size) / 2;
	trysort.i = 0;
	trysort.chk_size = size / trysort.nb_chk + 1;
	while (trysort.i < trysort.nb_chk)
	{
		trysort.j = trysort.chk_size;
		while (--trysort.j)
		{
			trysort.a = set_rotate(stk, trysort.nb_chk,
					trysort.i, &(trysort.rotate));
			the_while(stk, trysort.a, &trysort.rotate);
			while (trysort.rotate > 0)
			{
				ft_ra(&stk);
				trysort.rotate--;
			}
			while (trysort.rotate++ < 0)
				ft_rra(&stk);
			ft_pb(&stk);
		}
		trysort.i++;
	}
	final_pa(trysort.rotate, stk);
}

static int	*get_chunk(int *arr, int size, int nb_chk, int n)
{
	int	*res;
	int	i;
	int	chk_size;

	i = -1;
	chk_size = size / nb_chk + 1;
	res = malloc(sizeof(int) * chk_size);
	while (++i < chk_size)
		res[i] = arr[i + chk_size * n];
	return (res);
}

void	opti_rotate_b(t_stacks *stk, int a, int *rotate)
{
	int	rotate_b;

	rotate_b = minimaze_placement(*stk->b, a);
	while (rotate_b < 0)
	{
		if (*rotate < 0)
		{
			ft_rrr(&stk);
			(*rotate)++;
		}
		else
			ft_rrb(&stk);
		rotate_b++;
	}
	while (rotate_b--)
	{
		if (*rotate > 0)
		{
			ft_rr(&stk);
			(*rotate)--;
		}
		else
			ft_rb(&stk);
	}
}

static int	set_rotate(t_stacks *stk, int nb_chk, int i, int *rotate)
{
	int	*chunk;
	int	a;
	int	chk_size;

	chk_size = stk->size / nb_chk + 1;
	chunk = get_chunk(stk->array, stk->size, nb_chk, i);
	*rotate = minimaze_rotate(*stk->a, ft_tabmax(chunk, chk_size));
	if (*rotate < 0)
		a = *(int *)ft_lstcalendar(*stk->a,
				ft_lstsize(*stk->a) + *rotate)->cont;
	else
		a = *(int *)ft_lstcalendar(*stk->a, *rotate)->cont;
	free(chunk);
	return (a);
}
