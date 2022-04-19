/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:27:05 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/14 08:42:20 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_trysort
{
	int	chk_size;
	int	nb_chk;
	int	i;
	int	j;
	int	rotate;
	int	a;
}		t_trysort;

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
int		is_lstsorted_r(t_list *list);
void	stacks_print(t_stacks *stk);
void	trysort(t_stacks *stk);
void	trysortparttwo(t_stacks *stk);
int		minimaze_rotate(t_list *lst, int max);
int		minimaze_placement(t_list *lst, int to_place);
int		true_minimaze_rotate(t_list *lst, int max);
void	trysortmore(t_stacks *stk, size_t size);
int		ft_lstmaxint(t_list *lst);
int		closest_divisor(int size);
long	ps_atoi(const char *str);
void	the_while(t_stacks *stk, int a, int *rotate);
void	final_pa(int rotate, t_stacks *stk);
void	opti_rotate_b(t_stacks *stk, int a, int *rotate);
void	do_rb(int *rotate, t_stacks *stk);
void	do_rrb(int *rotate, t_stacks *stk);

# endif

#endif
