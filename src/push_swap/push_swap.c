/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:41 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/10 12:04:42 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_lswap	*stack_one;
	t_lswap *stack_two;

	if (!(stack_one = (t_lswap*)malloc(sizeof(t_lswap))))
		error();
	
	// stack_one->prev = (t_lswap*)malloc(sizeof(t_lswap));
	// stack_one->next = (t_lswap*)malloc(sizeof(t_lswap));
	stack_one->num = 0;
	stack_one->step1 = 0;
	stack_one->step2 = 0;
	stack_one->vec1 = 0;
	stack_one->vec2 = 0;
	// printf("%d, %d, %d, %d, %d\n", stack_one->num, stack_one->step1, stack_one->step2, stack_one->vec1, stack_one->vec2);
	printf("%lu\n", sizeof(stack_one->num));
	printf("%lu\n", sizeof(stack_one->step1));
	printf("%lu\n", sizeof(stack_one->step2));
	printf("%lu\n", sizeof(stack_one->vec1));
	printf("%lu\n", sizeof(stack_one->vec2));
	printf("%lu\n", sizeof(stack_one->next));
	printf("%lu\n", sizeof(stack_one->prev));
	printf("Total = %lu\n", sizeof(*stack_one));
	printf("Total required = %lu\n\n", sizeof(t_lswap));
	
	process_stack(&argc, &argv, stack_one);

t_lswap *test = stack_one;
	while (test)
	{
		printf("%d, %d, %d, %d, %d\n", test->num, test->step1, test->step2, test->vec1, test->vec2);
		test = test->next;
	}
	printf("\n\n");
	magic(stack_one, stack_two, argc - 1);
	// result(stack_one, stack_two);
	return (0);
}

void	magic(t_lswap *stack_one, t_lswap *stack_two, int len)
{
	t_lswap *stack;
	int min;
	int max;
	
	int len_a;
	int len_b;
	t_lswap *s1;
	t_lswap *s2;
	t_lswap *opt;
	int pos1;
	int pos2;
	int buf;

	stack = stack_one; //ищем макс и мин
	min = stack->num;
	max = stack->num;
	while (stack != NULL)
	{
		(min > stack->num) ? (min = stack->num) : 1;
		(max < stack->num) ? (max = stack->num) : 1;
		stack = stack->next;
	}
	while(len > 3) //перекидываем все, кроме 3 значений, в Б
	{
		if (stack_one->num != min && stack_one->num != max)
		{
			s_push(&stack_two, &stack_one, 2, 1);
			len--;
		}
		else
			s_rotate(&stack_one, 1, 1);
	}
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
////print
	s1 = stack_one;
	s2 = stack_two;

	ft_printf("\n\n");
	ft_printf("AFTER SORT A\n");
	 ft_printf("A ");
	while (s1 != NULL)
	{
		ft_printf("%d ", s1->num);
		s1 = s1->next;
	}
	 ft_printf("|\nB ");
	while (s2 != NULL)
	{
		ft_printf("%d ", s2->num);
		s2 = s2->next;
	}
	ft_printf("|\n\n");
//////////////////////////////////////////////////


	len_a = 3;//считаем длину А
	s2 = stack_two;//считаем длину Б
	len_b = 0;
	while (s2 != NULL)
	{
		len_b++;
		s2 = s2->next;
	}
	s2 = stack_two;

	t_lswap *test1 = stack_one;
	while (test1)
	{
		printf("%d, %d, %d, %d, %d\n", test1->num, test1->step1, test1->step2, test1->vec1, test1->vec2);
		test1 = test1->next;
	}
	printf("\n");
	t_lswap *test2 = stack_two;
	while (test2)
	{
		printf("%d, %d, %d, %d, %d\n", test2->num, test2->step1, test2->step2, test2->vec1, test2->vec2);
		test2 = test2->next;
	}
printf("\n\n");
int step2;
	while (len_b > 0)
	{
//		printf("2\n");
		
		//printf("len A = %d\n", len_a);
		//printf("len B = %d\n\n", len_b);
		int step1;
		pos2 = 0;
		while (s2 != NULL) //для каждого элемента в Б (записываем результаты в структуру этого элемента - сумма шагов, навправление А, направление Б):
		{
			pos1 = 0;
//			printf("3\n");
			buf = s2->num;
			//	1) считаем количество шагов в Б, направление (ниже середины или выше)
			if (pos2 > len_b / 2)
			{
				// printf("Var 1\n");
				s2->vec2 = -1;
				// printf("pos B = %d\n", pos2);
				// printf("len B = %d\n\n", len_b);
				int step2 = len_b - pos2;
				s2->step2 = step2;
				// printf("steps B int = %d\n", step2);
			}
			else
			{
				// printf("Var 2\n");
				s2->vec2 = 1;
				// printf("pos B = %d\n", pos2);
				// printf("len B = %d\n\n", len_b);
				int step2 = pos2;
				s2->step2 = pos2;
				// printf("steps B int = %d\n", step2);
			}
			// printf("steps B = %d\n\n", s2->step2);
			
				
			//	2) ищем место для помещения в А, считаем количесвто шагов, направление (ниже середины или выше)
			s1 = stack_one;
		//	ft_printf("pos A Start = %d\n", pos1);
			while (s1 != NULL)
			{
				//ft_printf("len A = %d\n", len_a);
				if (s1->num > buf)
				{
					if (pos1 > len_a / 2)
					{
						//printf("Var 1\n");
						s2->vec1 = -1;
						step1 = len_a - pos1;
						s2->step1 = step1;
					}
					else
					{
						//printf("Var 2\n");
						s2->vec1 = 1;
						step1 = pos1;
						s2->step1 = step1;
					}
					break ;
				}
				else
				{
					s1 = s1->next;
					pos1++;
				//	ft_printf("pos A = %d\n", pos1);
				}
			}
			// printf("\npos A fin = %d\n", pos1);
			// printf("steps A = %d\n\n", step1);
			s2 = s2->next;
			pos2++;
			// printf("\n");
		}
//////////////////////////////////////////////////////////CLEAN (MAYBE)
	//printf("4\n");
		s2 = stack_two;
		opt = s2;
		//printf("opt num before = %d\n", opt->num);
		while (s2 != NULL) //сравниваем сумму шагов, запоминаем элемент с самым малым количесвом
		{
			//printf("%d %d\n", opt->step1 + opt->step2, s2->step1 + s2->step2);
			if ((opt->step1 + opt->step2) > (s2->step1 + s2->step2))
				opt = s2;
			s2 = s2->next;
		}
		printf("opt num = %d\n", opt->num);
		//	для этого элемента выполняем операции, выводя на экран
		while (opt->step1 != 0 && opt->step2 != 0)
		{
			if (opt->step1 != 0 && opt->step2 != 0 && opt->vec1 == 1 && opt->vec2 == 1)
			{
				s_rotate_both(&stack_one, &stack_two, 1);
				(opt->step1--, opt->step2--);
			}
			else if (opt->step1 != 0 && opt->step2 != 0 && opt->vec1 == -1 && opt->vec2 == -1)
			{
				s_rev_rotate_both(&stack_one, &stack_two, 1);
				(opt->step1--, opt->step2--);
			}
			else if (opt->step1 != 0 && opt->vec1 == -1)
			{
				s_rev_rotate(&stack_one, 1, 1);
				opt->step1--;
			}
			else if (opt->step1 != 0 && opt->vec1 == 1)
			{
				s_rotate(&stack_one, 1, 1);
				opt->step1--;
			}
			else if (opt->step2 != 0 && opt->vec2 == -1)
			{
				s_rev_rotate(&stack_two, 2, 1);
				opt->step2--;
			}
			else if (opt->step2 != 0 && opt->vec2 == 1)
			{
				s_rotate(&stack_two, 2, 1);
				opt->step2--;
			}
			printf("again\n");
		}
		s_push(&stack_one, &stack_two, 1, 1);
	//	считаем длину А
		len_a++;
	//	считаем длину Б
		len_b--;
		//printf("7\n");
	break;
	}//	проверяем, пуст ли Б ( len_Б - 1 == 0), если пуст, то выходим из цикла
	s1 = stack_one;
	s2 = stack_two;

	ft_printf("\n\n");
	ft_printf("After 1st sort\n");
	 ft_printf("A ");
	while (s1 != NULL)
	{
		ft_printf("%d ", s1->num);
		s1 = s1->next;
	}
	 ft_printf("|\nB ");
	while (s2 != NULL)
	{
		ft_printf("%d ", s2->num);
		s2 = s2->next;
	}
	ft_printf("|\n\n");
///////////
// 	printf("71\n");
// 	s1 = stack_one;
// 	buf = 0;
// 	while (s1 != NULL || s1->num != min)//ищем мин
// 	{
// 		buf++;
// 		s1 = s1->next;
// 	}
// 	printf("8\n");
// //теперь крутим А, пока на первой позиции не окажется МИН
// 	if (buf > len_a / 2)
// 		while (stack_one->num != min)
// 			s_rev_rotate(&stack_one, 1, 1);
// 	else
// 		while (stack_one->num != min) //теперь крутим А, пока на первой позиции не окажется МИН
// 			s_rotate(&stack_one, 1, 1);
// printf("9\n");
// //////////////////////////////////////////////////////
// 	ft_printf("\n\n");
// 	ft_printf("After 2\n");
// 	 ft_printf("A ");
// 	while (stack_one != NULL)
// 	{
// 		ft_printf("%d ", stack_one->num);
// 		stack_one = stack_one->next;
// 	}
// 	 ft_printf("|\nB ");
// 	while (stack_two != NULL)
// 	{
// 		ft_printf("%d ", stack_two->num);
// 		stack_two = stack_two->next;
// 	}
// 	ft_printf("|\n\n");
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
