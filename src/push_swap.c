/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:18:16 by bdehais           #+#    #+#             */
/*   Updated: 2022/03/14 08:42:39 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init(t_stacks **stk, int n, char *args[]);
static int	washing_machine(t_stacks *stk, char **split);
static int	fill_stacks(int i, char *args[], t_stacks **stk);
static void	main_part2(t_stacks *stk, char **sp);

int	main(int ac, char *av[])
{
	t_stacks	*stk;
	char		**sp;
	int			s;

	sp = NULL;
	if (ac >= 3 && (init(&stk, ac - 1, av + 1) < 0
			|| !ft_is_nodoubl(stk->array, ac - 1)))
	{
		ft_putendl_fd("Error", 2);
		return (washing_machine(stk, sp));
	}
	else if (ac == 2)
	{
		sp = ft_split(av[1], ' ');
		s = ft_tab_size(sp);
		if (init(&stk, s, sp) < 0 || !ft_is_nodoubl(stk->array, s))
		{
			ft_putendl_fd("Error", 2);
			return (washing_machine(stk, sp));
		}
	}
	if (ac >= 2)
		main_part2(stk, sp);
	exit (0);
}

static void	main_part2(t_stacks *stk, char **sp)
{
	trysort(stk);
	washing_machine(stk, sp);
}

static int	init(t_stacks **stk, int nb, char *args[])
{
	int		i;

	i = -1;
	(*stk) = malloc (sizeof (t_stacks));
	if (!(*stk))
		return (-42);
	(*stk)->a = malloc(sizeof(t_list *));
	(*stk)->b = malloc(sizeof(t_list *));
	(*stk)->array = malloc (sizeof (int) * nb);
	if (!(*stk)->array)
		return (-42);
	while (++i < nb)
		if (fill_stacks(i, args, stk) < 0)
			return (-42);
	(*stk)->min = ft_tabmin((*stk)->array, (size_t) i);
	(*stk)->max = ft_tabmax((*stk)->array, (size_t) i);
	(*stk)->size = nb;
	ft_sort_int_tab((*stk)->array, (*stk)->size);
	return (1);
}

static int	washing_machine(t_stacks *stk, char **split)
{
	ft_lstclear(stk->a, free);
	ft_lstclear(stk->b, free);
	free(stk->array);
	free(stk);
	free(split);
	return (1);
}

static int	fill_stacks(int i, char *args[], t_stacks **stk)
{
	long	almost_int;
	int		*cont;
	t_list	*tmp;

	almost_int = ps_atoi(args[i]);
	if (almost_int <= ERROR)
		return (-42);
	cont = malloc(sizeof(int));
	if (!cont)
		return (-42);
	*cont = (int) almost_int;
	tmp = ft_lstnew(cont);
	if (!tmp)
		return (-42);
	ft_lstadd_back((*stk)->a, tmp);
	(*stk)->array[i] = *((int *) tmp->cont);
	return (1);
}
