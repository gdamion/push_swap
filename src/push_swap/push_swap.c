/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:41 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/12 13:52:20 by gdamion-         ###   ########.fr       */
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

int		ordered(t_lswap	*s, int len)
{
	int		buf;
	t_lswap	*lbuf;
	short	mark;
	int		min;
	int		pos;

	lbuf = s;
	while (lbuf->next)
		lbuf = lbuf->next;
	buf = lbuf->num;
	mark = 0;
	lbuf = s;
	while (lbuf)
	{
		if (buf > lbuf->num)
		{
			mark++;
			min = lbuf->num;
		}
		buf = lbuf->num;
		lbuf = lbuf->next;
	}
	if (mark > 1)
		return (0);
	if (mark == 1)
	{
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
	// print_stacks(s, NULL);
	return (1);
}

void	magic(t_lswap *stack_one, t_lswap *stack_two, int len)
{
	int len_a;
	int len_b;
	t_lswap *opt;
	int min;
	
	// print_stacks(stack_one, stack_two);//
	min = drop_to_b(&stack_one, &stack_two, len);
	len_a = lst_len(stack_one);
	len_b = lst_len(stack_two);
	// print_stacks(stack_one, stack_two);//
	while (len_b > 0)
	{
		// ft_printf("\n--------------------\n");
		// ft_printf("len_a = %d\n", len_a);
		// ft_printf("len_b = %d\n\n", len_b);
		predict_all(stack_one, stack_two, len_a, len_b);
		find_best(&opt, stack_two);
		exec(&stack_one, &stack_two, opt);
		len_a++;
		len_b--;
		// print_stacks(stack_one, stack_two);//
		// ft_printf("\n--------------------\n");
	}
	final_moves(&stack_one, min, len_a);
	// print_stacks(stack_one, stack_two);//
	exit(0);
}

int		drop_to_b(t_lswap **stack_one, t_lswap **stack_two, int len)
{
	t_lswap *s;
	int min;
	int max;

	s = *stack_one; //ищем макс и мин
	min = s->num;
	max = s->num;
	while (s != NULL)
	{
		(min > s->num) ? (min = s->num) : 1;
		(max < s->num) ? (max = s->num) : 1;
		s = s->next;
	}
	while(len > 3) //перекидываем все, кроме 3 значений, в Б
	{
		if ((*stack_one)->num != min && (*stack_one)->num != max)
		{
			s_push(stack_two, stack_one, 2, 1);
			len--;
		}
		else
			s_rotate(stack_one, 1, 1);
	}
	//print_stacks(*stack_one, *stack_two);//
	s = *stack_one;
	if (s->next->num == min && s->next->next->num == max)
		s_swap(stack_one, 1, 1);
	else if (s->num == max && s->next->num == min)
		s_rotate(stack_one, 1, 1);
	else if (s->num == max && s->next->next->num == min)
		(s_rotate(stack_one, 1, 1), s_swap(stack_one, 1, 1));
	else if (s->next->num == max && s->next->next->num == min)
		s_rev_rotate(stack_one, 1, 1);
	else if (s->num == min && s->next->num == max)
		(s_rev_rotate(stack_one, 1, 1), s_swap(stack_one, 1, 1));
	//print_stacks(*stack_one, *stack_two);//
	return (min);
}

void	predict_all(t_lswap *s1, t_lswap *s2, int len_a, int len_b)
{
	int pos2;
	int step2;
	int buf;
	t_lswap *buf_s1;

	pos2 = 0;
	while (s2 != NULL) //для каждого элемента в Б (записываем результаты в структуру этого элемента - сумма шагов, навправление А, направление Б):
	{
		buf = s2->num;
		//	1) считаем количество шагов в Б, направление (ниже середины или выше)
		if (pos2 > len_b / 2)
		{
			// printf("Var 1B\n");
			s2->vec2 = -1;
			// printf("len B = %d\n\n", len_b);
			step2 = len_b - pos2;
		}
		else
		{
			// printf("Var 2B\n");
			s2->vec2 = 1;
			// printf("len B = %d\n\n", len_b);
			step2 = pos2;
		}
		s2->step2 = step2;
		// ft_printf("----\num B = %d\n", buf);
		// ft_printf("pos B = %d\n", pos2);
		// ft_printf("steps B = %d\n", s2->step2);
		// ft_printf("vec B = %d\n\n", s2->vec2);
		//	2) ищем место для помещения в А, считаем количесвто шагов, направление (ниже середины или выше)
		predict_in_a(s1, s2, buf, len_a);
		// printf("\npos A fin = %d\n", pos1);
		// printf("steps A = %d\n\n", step1);
		s2 = s2->next;
		pos2++;
		// printf("\n");
	}
}

void	predict_in_a(t_lswap *s1, t_lswap *s2, int buf, int len_a)
{
	int pos1;
	int step1;
	t_lswap *last;
	int prev;
	int max;

	last = s1;
	while (last->next)
		last = last->next;
	prev = last->num;

	last = s1;
	max = last->num;
	while (last)
	{
		if (last->num > max)
			max = last->num;
		last = last->next;
	}
	pos1 = 0;

	while (s1 != NULL)
	{
		//ft_printf("len A = %d\n", len_a);
		if ((prev < buf && buf < s1->num) || (prev == max && buf < s1->num))//?????????????????????/
		{
			if (pos1 > len_a / 2)
			{
			//	printf("Var 1A\n");
				s2->vec1 = -1;
				step1 = len_a - pos1;
				s2->step1 = step1;
			}
			else
			{
			//	printf("Var 2A\n");
				s2->vec1 = 1;
				step1 = pos1;
				s2->step1 = step1;
			}
			// ft_printf("pos A = %d\n", pos1);
			// ft_printf("step A = %d\n", s2->step1);
			// ft_printf("vec A = %d\n----\n\n", s2->vec1);
			break ;
		}
		prev = s1->num;
		s1 = s1->next;
		pos1++;
	}
}

void	find_best(t_lswap **opt, t_lswap *s2)
{
	*opt = s2;
	while (s2 != NULL) //сравниваем сумму шагов, запоминаем элемент с самым малым количесвом
	{
		//printf("STEPS: prev opt = %d, curr = %d\n", (*opt)->step1 + (*opt)->step2, s2->step1 + s2->step2);
		if (((*opt)->step1 + (*opt)->step2) > (s2->step1 + s2->step2))
			*opt = s2;
		s2 = s2->next;
	}
	// ft_printf("opt num = %d\nsteps A = %d, vector A = %hd\nsteps B = %d, vector B = %hd\n",
				// (*opt)->num, (*opt)->step1, (*opt)->vec1, (*opt)->step2, (*opt)->vec2);
}

void	exec(t_lswap **stack_one, t_lswap **stack_two, t_lswap *opt)
{
	while (opt->step1 > 0 || opt->step2 > 0)
	{
		if (opt->step1 != 0 && opt->step2 != 0 && opt->vec1 == 1 && opt->vec2 == 1)
			(s_rotate_both(stack_one, stack_two, 1), opt->step1--, opt->step2--);
		else if (opt->step1 != 0 && opt->step2 != 0 && opt->vec1 == -1 && opt->vec2 == -1)
			(s_rev_rotate_both(stack_one, stack_two, 1), opt->step1--, opt->step2--);
		else if (opt->step1 != 0 && opt->vec1 == -1)
			(s_rev_rotate(stack_one, 1, 1), opt->step1--);
		else if (opt->step1 != 0 && opt->vec1 == 1)
			(s_rotate(stack_one, 1, 1), opt->step1--);
		else if (opt->step2 != 0 && opt->vec2 == -1)
			(s_rev_rotate(stack_two, 2, 1), opt->step2--);
		else if (opt->step2 != 0 && opt->vec2 == 1)
			(s_rotate(stack_two, 2, 1), opt->step2--);
	}
	s_push(stack_one, stack_two, 1, 1);
}

void	final_moves(t_lswap **s1, int min, int len_a)
{
	int buf;
	t_lswap *s1_buf;

	buf = 0;
	s1_buf = *s1;
	while (s1_buf != NULL)//ищем мин
	{
		if (s1_buf->num == min)
			break;
		buf++;
		s1_buf = s1_buf->next;
	}
	//print_stacks(*s1, NULL);//
	//ft_printf("buf = %d, len_a/2 = %d, \n", buf, len_a/2);
	if (buf > len_a / 2)//теперь крутим А, пока на первой позиции не окажется МИН
		while ((*s1)->num != min)
			s_rev_rotate(s1, 1, 1);
	else
		while ((*s1)->num != min) //теперь крутим А, пока на первой позиции не окажется МИН
			s_rotate(s1, 1, 1);
}

int	lst_len(t_lswap	*lst)
{
	int len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return(len);
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
		stack_one->num, stack_one->step1, stack_one->step2, stack_one->vec1, stack_one->vec2);
		stack_one = stack_one->next;
	}
	ft_printf("\nB\n");
	while (stack_two)
	{
		ft_printf("%d, %d, %d, %d, %d\n",
		stack_two->num, stack_two->step1, stack_two->step2, stack_two->vec1, stack_two->vec2);
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