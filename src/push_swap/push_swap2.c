/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:55:48 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 16:58:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		drop_to_b(t_lswap **stack_one, t_lswap **stack_two, int len)
{
	t_lswap	*s;
	int		min;
	int		max;

	s = *stack_one;
	min = s->num;
	max = s->num;
	while (s != NULL)
	{
		(min > s->num) ? (min = s->num) : 1;
		(max < s->num) ? (max = s->num) : 1;
		s = s->next;
	}
	while (len > 3)
	{
		if ((*stack_one)->num != min && (*stack_one)->num != max)
		{
			s_push(stack_two, stack_one, 2, 1);
			len--;
		}
		else
			s_rotate(stack_one, 1, 1);
	}
	sort_rest(stack_one, min, max);
	return (min);
}

void	sort_rest(t_lswap **s, int min, int max)
{
	if ((*s)->next->num == min && (*s)->next->next->num == max)
		s_swap(s, 1, 1);
	else if ((*s)->num == max && (*s)->next->num == min)
		s_rotate(s, 1, 1);
	else if ((*s)->num == max && (*s)->next->next->num == min)
	{
		s_rotate(s, 1, 1);
		s_swap(s, 1, 1);
	}
	else if ((*s)->next->num == max && (*s)->next->next->num == min)
		s_rev_rotate(s, 1, 1);
	else if ((*s)->num == min && (*s)->next->num == max)
	{
		s_rev_rotate(s, 1, 1);
		s_swap(s, 1, 1);
	}
}

void	predict_all(t_lswap *s1, t_lswap *s2, int len_a, int len_b)
{
	int		pos2;
	t_lswap *buf_s1;

	pos2 = 0;
	while (s2)
	{
		if (pos2 > len_b / 2)
		{
			s2->vec2 = -1;
			s2->step2 = len_b - pos2;
		}
		else
		{
			s2->vec2 = 1;
			s2->step2 = pos2;
		}
		predict_in_a(s1, s2, len_a);
		s2 = s2->next;
		pos2++;
	}
}

void	predict_in_a(t_lswap *s1, t_lswap *s2, int len_a)
{
	t_lswap	*last;
	int		buf[3];

	buf[2] = len_a;
	last = s1;
	while (last->next)
		last = last->next;
	buf[0] = last->num;
	last = s1;
	buf[1] = last->num;
	while (last)
	{
		if (last->num > buf[1])
			buf[1] = last->num;
		last = last->next;
	}
	calc_steps_a(s1, s2, buf);
}

void	calc_steps_a(t_lswap *s1, t_lswap *s2, int buf[3])
{
	int		pos1;

	pos1 = 0;
	while (s1)
	{
		if ((buf[0] < s2->num && s2->num < s1->num)
		|| (buf[0] == buf[1] && s2->num < s1->num))
		{
			if (pos1 > buf[2] / 2)
			{
				s2->vec1 = -1;
				s2->step1 = buf[2] - pos1;
			}
			else
			{
				s2->vec1 = 1;
				s2->step1 = pos1;
			}
			break ;
		}
		buf[0] = s1->num;
		s1 = s1->next;
		pos1++;
	}
}
