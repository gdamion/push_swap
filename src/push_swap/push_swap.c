/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:41 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/09 15:30:40 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_lswap	*stack_one;
	t_lswap *stack_two;

	if (!(stack_one = (t_lswap*)malloc(sizeof(t_list))))
		error();
	process_stack(&argc, &argv, stack_one);
	magic(stack_one, stack_two, argc - 1);
	// result(stack_one, stack_two);
	return (0);
}

void	magic(t_lswap *stack_one, t_lswap *stack_two, int len)
{
	t_lswap *stack;
	int min;
	int max;
int i = 0;
	// printf("%d\n", i++);
	stack = stack_one; //ищем макс и мин
	min = stack->num;
	max = stack->num;
	while (stack != NULL)
	{
		(min > stack->num) ? (min = stack->num) : 1;
		(max < stack->num) ? (max = stack->num) : 1;
		stack = stack->next;
	}
	// printf("%d\n", i++);
	// while(len > 3) //перекидываем все, кроме 3 значений, в Б
	// {
	// 	if (stack_one->num != min && stack_one->num != max)
	// 		s_push(&stack_two, &stack_one, 2, 1);
	// 	else
	// 		s_rotate(&stack_one, 1, 1);
	// }
	// printf("%d\n", i++);
	if (stack_one->num == max) //сортируем оставшиеся 3 символа в А
		s_rotate(&stack_one, 1, 1);
	else if (stack_one->num != min && stack_one->next->num == min)
		s_swap(&stack_one, 1, 1);
	else if (stack_one->num == min && stack_one->next->num == max)
	{
		s_rotate(&stack_one, 1, 1);
		s_swap(&stack_one, 1, 1);
	}
	else
		s_rev_rotate(&stack_one, 1, 1);
	// printf("%d\n", i++);
//////////////////////////////////////////////////
	int len_a;
	int len_b;
	t_lswap *s1;
	t_lswap *s2;
	t_lswap *opt;
	int pos1;
	int pos2;
	int buf;
	// printf("%d\n", i++);
	//	считаем длину А
	len_a = 3;

	//	считаем длину Б
	s2 = stack_two;
	len_b = 0;
	while (s2 != NULL)
	{
		len++;
		s2 = s2->next;
	}
	// printf("%d\n", i++);
	s2 = stack_two;
	//ЦИКЛ
	while (len_b > 0)
	{
		pos1 = 0;
		pos2 = 0;
	//	ЦИКЛ
		while (s2 != NULL) //для каждого элемента в Б (записываем результаты в структуру этого элемента - сумма шагов, навправление А, направление Б):
		{
			buf = s2->num;
			//	1) считаем количество шагов в Б, направление (ниже середины или выше)
			(pos2 > len_b / 2) ? (s2->vec2 = -1, s2->step2 = len_b - pos2) : (s2->vec2 = 1, s2->step2 = pos2);
			//	2) ищем место для помещения в А, считаем количесвто шагов, направление (ниже середины или выше)
			s1 = stack_one;
			while (s1 != NULL)
			{
				if (s1-> num > buf)
				{
					(pos1 > len_a / 2) ? (s2->vec1 = -1, s2->step1 = len_a - pos1) : (s2->vec1 = 1, s2->step1 = pos1);
					break ;
				}
				else
				{
					s1 = s1->next;
					pos1++;
				}
			}
			s2 = s2->next;
			pos2++;
		}
		// printf("%d\n", i++);
		s2 = stack_two;
		opt = s2;
		// ЦИКЛ
		while (s2 != NULL) //сравниваем сумму шагов, запоминаем элемент с самым малым количесвом
		{
			if (opt->step1 + opt->step2 > s2->step1 + s2->step2)
				opt = s2;
			s2 = s2->next;
		}
	// printf("%d\n", i++);
		//	для этого элемента выполняем операции, выводя на экран
		while (opt->step1 != 0 && opt->step2 != 0)
		{
			if (opt->step1 != 0 && opt->step2 != 0 && opt->vec1 == 1 && opt->vec2 == 1)
				s_rotate_both(&stack_one, &stack_two, 1);
			else if (opt->step1 != 0 && opt->step2 != 0 && opt->vec1 == -1 && opt->vec2 == -1)
				s_rev_rotate_both(&stack_one, &stack_two, 1);
			else if (opt->step1 != 0 && opt->vec1 == -1)
				s_rev_rotate(&stack_one, 1, 1);
			else if (opt->step1 != 0 && opt->vec1 == 1)
				s_rotate(&stack_one, 1, 1);
			else if (opt->step2 != 0 && opt->vec2 == -1)
				s_rev_rotate(&stack_two, 2, 1);
			else if (opt->step2 != 0 && opt->vec2 == 1)
				s_rotate(&stack_two, 2, 1);
		}
		s_push(&stack_one, &stack_two, 1, 1);
	// printf("%d\n", i++);
	//	считаем длину А
		len_a++;
	//	считаем длину Б
		len_b--;
	}//	проверяем, пуст ли Б ( len_Б - 1 == 0), если пуст, то выходим из цикла
	// printf("%d\n", i++);
	s1 = stack_one;
	buf = 0;
	while (s1->num != min)//ищем мин
	{
		s1 = s1->next;
		buf++;
	}
	// printf("%d\n", i++);
//теперь крутим А, пока на первой позиции не окажется МИН
	if (buf > len_a / 2)
		while (stack_one->num != min)
			s_rev_rotate(&stack_one, 1, 1);
	else
		while (stack_one->num != min) //теперь крутим А, пока на первой позиции не окажется МИН
			s_rotate(&stack_one, 1, 1);
		// printf("%d\n", i++);
//////////////////////////////////////////////////////
	ft_printf("\n\n");
	ft_printf("After\n");
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
	exit(0);
}

// void	result(t_lswap	*s1, t_lswap *s2)
// {
// 	// ft_printf("\n\n");
// 	// ft_printf("After\n");
// 	//  ft_printf("A ");
// 	// while (s1 != NULL)
// 	// {
// 	// 	ft_printf("%d ", s1->num);
// 	// 	s1 = s1->next;
// 	// }
// 	//  ft_printf("|\nB ");
// 	// while (s2 != NULL)
// 	// {
// 	// 	ft_printf("%d ", s2->num);
// 	// 	s2 = s2->next;
// 	// }
// 	// ft_printf("|\n\n");
// 	// exit(0);
// }
