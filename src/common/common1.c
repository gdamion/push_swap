/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 18:44:10 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int		process_stack(int *argc, char ***argv, t_lswap *nums)
{
	int			args;
	char		**curr_arg;
	int			i;

	args = 1;
	nums->prev = NULL;
	nums->next = NULL;
	i = 0;
	while (args < (*argc))
	{
		curr_arg = ft_strsplit((*argv)[args], ' ');
		foreach_arg(&nums, curr_arg, &i);
		args++;
	}
	return (i);
}

void		foreach_arg(t_lswap **nums, char **curr_arg, int *i)
{
	long long	num;
	int			a;

	a = 0;
	while (curr_arg[a] != NULL)
	{
		num = ft_atoi_simple_big(curr_arg[a]);
		if (num < -2147483648 || 2147483647 < num)
			error();
		if (*i > 0)
			add_el_and_check(nums, num);
		(*nums)->num = (int)num;
		(*nums)->next = NULL;
		(*i)++;
		free(curr_arg[a]);
		a++;
	}
	free(curr_arg);
}

void	add_el_and_check(t_lswap **nums, long long num)
{
	t_lswap		*nums_check;

	add_next(nums);
	nums_check = (*nums)->prev;
	while (nums_check->prev != NULL)
	{
		if (num == nums_check->num)
			error();
		nums_check = nums_check->prev;
	}
	if (num == nums_check->num)
			error();
}

void	add_next(t_lswap **curr)
{
	t_lswap *buf;

	buf = *curr;
	if (!((*curr)->next = (t_lswap*)malloc(sizeof(t_lswap))))
		error();
	*curr = (*curr)->next;
	(*curr)->prev = buf;
	(*curr)->next = NULL;
	(*curr)->num = 0;
	(*curr)->step1 = 0;
	(*curr)->step2 = 0;
	(*curr)->vec1 = 0;
	(*curr)->vec2 = 0;
}
