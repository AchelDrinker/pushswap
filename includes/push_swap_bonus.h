/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:27:05 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/11 17:08:35 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

# ifndef T_STACKS
#  define T_STACKS

#  ifndef ERROR
#   define ERROR -2147483649
#  endif

typedef struct s_stacks {
	size_t	size;
	t_list	**a;
	t_list	**b;
	int		min;
	int		max;
	int		*array;
}			t_stacks;

void	ft_pb(t_stacks **stk);
void	ft_pa(t_stacks **stk);
void	ft_ra(t_stacks **stk);
void	ft_rra(t_stacks **stk);
void	ft_rb(t_stacks **stk);
void	ft_rrb(t_stacks **stk);
void	ft_rr(t_stacks **stk);
void	ft_rrr(t_stacks **stk);
void	ft_sa(t_stacks **stk);
void	ft_sb(t_stacks **stk);
void	ft_ss(t_stacks **stk);
int		is_lstsorted(t_list *list);
void	check_stdin(t_stacks *stk);
long	ps_atoi(const char *str);

# endif

#endif
