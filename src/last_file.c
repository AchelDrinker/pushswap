/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:56:21 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/11 14:56:55 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	true_minimaze_rotate(t_list *lst, int max)
{
	int		r_count;
	int		rr_count;

	r_count = 0;
	while (lst && *(int *)lst->cont != max)
	{
		lst = lst->nx;
		r_count++;
	}
	rr_count = -1;
	while (lst
		&& *(int *)(ft_lstcalendar(lst, ft_lstsize(lst) + rr_count)->cont)
		!= max)
		rr_count--;
	if (ft_abs(r_count) < ft_abs(rr_count))
		return (r_count);
	return (rr_count);
}

int	ft_lstmaxint(t_list *lst)
{
	int	max;

	max = -2147483648;
	while (lst)
	{
		if (max < *(int *)lst->cont)
		{
			max = *(int *)lst->cont;
		}
		lst = lst->nx;
	}
	return (max);
}

int	closest_divisor(int size)
{
	int	res;
	int	res_;

	res = ft_sqrt(size);
	if (res * res == size)
		return (res);
	else
	{
		res_ = res;
		while (1)
		{
			res++;
			res_--;
			if (size / (res / 2) * (res / 2) == size)
				return (res);
			if (size / (res_ / 2) * (res_ / 2) == size)
				return (res_);
		}
	}
}

long	ps_atoi(const char *str)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	sign = 1;
	value = 0;
	if ((str[i] == '+' || str[i] == '-') && ft_strlen(str) > 1)
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			value = value * 10 + str[i++] - '0';
		else
			return (ERROR);
	}
	if (sign * value <= 2147483647l && sign * value >= -2147483648l)
		return (sign * (int) value);
	return (ERROR);
}
