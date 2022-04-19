/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:30:30 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/11 12:11:04 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_lstsorted(t_list *lst)
{
	while (lst && lst->nx)
	{
		if (*(int *)lst->cont > *(int *)lst->nx->cont)
			return (0);
		lst = lst->nx;
	}
	return (1);
}

int	is_lstsorted_r(t_list *lst)
{
	while (lst && lst->nx)
	{
		if (*(int *)lst->cont < *(int *)lst->nx->cont)
			return (0);
		lst = lst->nx;
	}
	return (1);
}

void	stacks_print(t_stacks *stk)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = *(stk->a);
	lst_b = *(stk->b);
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			ft_putnbr_fd(*(int *) lst_a->cont, 1);
			lst_a = lst_a->nx;
		}
		ft_putstr_fd("\t\t\t\t", 1);
		if (lst_b)
		{
			ft_putnbr_fd(*(int *) lst_b->cont, 1);
			lst_b = lst_b->nx;
		}
		ft_putchar_fd('\n', 1);
	}
}

int	minimaze_rotate(t_list *lst, int max)
{
	int		r_count;
	int		rr_count;

	r_count = 0;
	while (lst && *(int *)lst->cont > max)
	{
		lst = lst->nx;
		r_count++;
	}
	rr_count = -1;
	while (lst && *(int *)(ft_lstcalendar(lst, ft_lstsize(lst)
			+ rr_count)->cont) > max)
		rr_count--;
	if (ft_abs(r_count) < ft_abs(rr_count))
		return (r_count);
	return (rr_count);
}

int	minimaze_placement(t_list *lst, int to_place)
{
	int		r_count;
	int		rr_count;

	r_count = 0;
	while (*(int *)(ft_lstcalendar(lst, r_count)->cont) > to_place)
		r_count++;
	rr_count = -1;
	while (*(int *)(ft_lstcalendar(lst, ft_lstsize(lst) + rr_count)->cont)
		< to_place)
		rr_count--;
	if (ft_abs(r_count) < ft_abs(rr_count))
		return (r_count);
	return (rr_count);
}
