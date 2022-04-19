/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:04:31 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/11 17:08:26 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
