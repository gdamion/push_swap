/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:20 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 16:58:42 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_best(t_lswap **opt, t_lswap *s2)
{
	*opt = s2;
	while (s2)
	{
		if (((*opt)->step1 + (*opt)->step2) > (s2->step1 + s2->step2))
			*opt = s2;
		s2 = s2->next;
	}
}

void	exec(t_lswap **stack_one, t_lswap **stack_two, t_lswap *opt)
{
	while (opt->step1 > 0 || opt->step2 > 0)
	{
		if (!exec_conditions1(stack_one, stack_two, opt))
			exec_conditions2(stack_one, stack_two, opt);
	}
	s_push(stack_one, stack_two, 1, 1);
}

int		exec_conditions1(t_lswap **stack_one, t_lswap **stack_two, t_lswap *opt)
{
	if (opt->step1 != 0 && opt->step2 != 0 && opt->vec1 == 1
					&& opt->vec2 == 1)
	{
		s_rotate_both(stack_one, stack_two, 1);
		opt->step1--;
		opt->step2--;
		return (1);
	}
	else if (opt->step1 != 0 && opt->step2 != 0 && opt->vec1 == -1
				&& opt->vec2 == -1)
	{
		s_rev_rotate_both(stack_one, stack_two, 1);
		opt->step1--;
		opt->step2--;
		return (1);
	}
	else if (opt->step1 != 0 && opt->vec1 == -1)
	{
		s_rev_rotate(stack_one, 1, 1);
		opt->step1--;
		return (1);
	}
	return (0);
}

void	exec_conditions2(t_lswap **stack_one, t_lswap **stack_two, t_lswap *opt)
{
	if (opt->step1 != 0 && opt->vec1 == 1)
	{
		s_rotate(stack_one, 1, 1);
		opt->step1--;
	}
	else if (opt->step2 != 0 && opt->vec2 == -1)
	{
		s_rev_rotate(stack_two, 2, 1);
		opt->step2--;
	}
	else if (opt->step2 != 0 && opt->vec2 == 1)
	{
		s_rotate(stack_two, 2, 1);
		opt->step2--;
	}
}

void	final_moves(t_lswap **s1, int min, int len_a)
{
	int		buf;
	t_lswap	*s1_buf;

	buf = 0;
	s1_buf = *s1;
	while (s1_buf != NULL)
	{
		if (s1_buf->num == min)
			break ;
		buf++;
		s1_buf = s1_buf->next;
	}
	if (buf > len_a / 2)
		while ((*s1)->num != min)
			s_rev_rotate(s1, 1, 1);
	else
		while ((*s1)->num != min)
			s_rotate(s1, 1, 1);
}
