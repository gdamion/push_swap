/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:41 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 13:36:46 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_lswap	*stack_one;
	t_lswap *stack_two;
	int		flag;

	if (!(stack_one = (t_lswap*)malloc(sizeof(t_lswap))))
		error();
	el_zerofill(stack_one);
	flag = process_stack(&argc, &argv, stack_one);
	if (!ordered(stack_one, argc - 1, flag))
		magic(stack_one, stack_two, argc - 1, flag);
	return (0);
}

int		ordered(t_lswap *s, int len, int flag)
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
	flag ? print_stacks(s, NULL) : 1;
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

int		lst_len(t_lswap *lst)
{
	int len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	print_stacks(t_lswap *stack_one, t_lswap *stack_two)
{
	ft_printf("\n\n");
	ft_printf("A ");
	while (stack_one != NULL)
	{
		ft_printf("%d ", stack_one->num);
		stack_one = stack_one->next;
	}
	ft_printf("|\nB ");
	while (stack_two != NULL)
	{
		ft_printf("%d ", stack_two->num);
		stack_two = stack_two->next;
	}
	ft_printf("|\n\n");
}

void	print_stack_info(t_lswap *stack_one, t_lswap *stack_two)
{
	ft_printf("\nA\n");
	while (stack_one)
	{
		ft_printf("%d, %d, %d, %d, %d\n",
		stack_one->num, stack_one->step1, stack_one->step2,
						stack_one->vec1, stack_one->vec2);
		stack_one = stack_one->next;
	}
	ft_printf("\nB\n");
	while (stack_two)
	{
		ft_printf("%d, %d, %d, %d, %d\n",
		stack_two->num, stack_two->step1, stack_two->step2,
						stack_two->vec1, stack_two->vec2);
		stack_two = stack_two->next;
	}
	ft_printf("\n\n");
}

void	el_zerofill(t_lswap *el)
{
	el->prev = NULL;
	el->next = NULL;
	el->num = 0;
	el->step1 = 0;
	el->step2 = 0;
	el->vec1 = 0;
	el->vec2 = 0;
}
