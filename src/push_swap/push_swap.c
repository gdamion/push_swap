/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:41 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/08 21:53:50 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_lswap	*cmds;
	t_lswap	*stack_one;
	t_lswap *stack_two;

	if (!(stack_one = (t_lswap*)malloc(sizeof(t_list)))
		|| !(cmds = (t_lswap*)malloc(sizeof(t_list))))
		error();
	process_stack(&argc, &argv, stack_one);
	magic(stack_one, stack_two, cmds, argc - 1);
	result(cmds);
	return (0);
}

void	magic(t_lswap *stack_one, t_lswap *stack_two, t_lswap *cmds, int len)
{
	t_lswap *stack;
	int min;
	int max;

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
			s_push(stack_two, stack_one, 2, 1);
		else
			s_rotate(stack_one, 1, 1);
	}

	if (stack_one->num == max) //сортируем оставшиеся 3 символа в А
		s_rotate(stack_one, 1, 1);
	else if (stack_one->num != min && stack_one->next->num == min)
		s_swap(stack_one, 1, 1);
	else if (stack_one->num == min && stack_one->next->num == max)
	{
		s_rotate(stack_one, 1, 1);
		s_swap(stack_one, 1, 1);
	}
	else
		s_rev_rotate(stack_one, 1, 1);
}

void	result(	t_lswap	*cmds)
{
	while (cmds != NULL)
	{
		(cmds->num == 1) ? ft_putendl("sa") : 1;
		(cmds->num == 2) ? ft_putendl("sb") : 1;
		(cmds->num == 3) ? ft_putendl("ss") : 1;
		(cmds->num == 4) ? ft_putendl("pa") : 1;
		(cmds->num == 5) ? ft_putendl("pb") : 1;
		(cmds->num == 6) ? ft_putendl("ra") : 1;
		(cmds->num == 7) ? ft_putendl("rb") : 1;
		(cmds->num == 8) ? ft_putendl("rr") : 1;
		(cmds->num == 9) ? ft_putendl("rra") : 1;
		(cmds->num == 10) ? ft_putendl("rrb") : 1;
		(cmds->num == 11) ? ft_putendl("rrr") : 1;
		cmds = cmds->next;
	}
	exit(0);
}
