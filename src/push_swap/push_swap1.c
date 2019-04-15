/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:41 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 17:04:48 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_lswap	*stack_one;
	t_lswap *stack_two;

	if (!(stack_one = (t_lswap*)malloc(sizeof(t_lswap))))
		error();
	el_zerofill(stack_one);
	process_stack(&argc, &argv, stack_one);
	if (!ordered(stack_one, argc - 1))
		magic(stack_one, stack_two, argc - 1);
	return (0);
}

int		ordered(t_lswap *s, int len)
{
	int		buf[3];
	t_lswap	*lbuf;

	lbuf = s;
	while (lbuf->next)
		lbuf = lbuf->next;
	buf[0] = lbuf->num;
	buf[1] = 0;
	lbuf = s;
	while (lbuf)
	{
		if (buf[0] > lbuf->num)
		{
			buf[1]++;
			buf[2] = lbuf->num;
		}
		buf[0] = lbuf->num;
		lbuf = lbuf->next;
	}
	if (buf[1] > 1)
		return (0);
	(buf[1] == 1) ? rotate(s, len, buf[2]) : 1;
	return (1);
}

void	rotate(t_lswap *s, int len, int min)
{
	t_lswap	*lbuf;
	int		pos;

	lbuf = s;
	pos = 0;
	while (lbuf->num != min)
	{
		pos++;
		lbuf = lbuf->next;
	}
	if (pos > len / 2)
		while (s->num != min)
			s_rev_rotate(&s, 1, 1);
	else
		while (s->num != min)
			s_rotate(&s, 1, 1);
}

void	magic(t_lswap *stack_one, t_lswap *stack_two, int len, int flag)
{
	int		len_a;
	int		len_b;
	t_lswap	*opt;
	int		min;

	min = drop_to_b(&stack_one, &stack_two, len);
	len_a = lst_len(stack_one);
	len_b = lst_len(stack_two);
	while (len_b > 0)
	{
		predict_all(stack_one, stack_two, len_a, len_b);
		find_best(&opt, stack_two);
		exec(&stack_one, &stack_two, opt);
		len_a++;
		len_b--;
	}
	final_moves(&stack_one, min, len_a);
	exit(0);
}
