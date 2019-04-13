/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/13 11:05:27 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int			main(int argc, char **argv)
{
	//ft_putendl("\nTIME FOR CHECKER BITCH\n");
	//ft_printf("args ps = %d\n", argc - 1);
	t_lswap	*cmds;
	t_lswap	*stack_one;
	t_lswap *stack_two;

	if (!(stack_one = (t_lswap*)malloc(sizeof(t_lswap)))
		|| !(cmds = (t_lswap*)malloc(sizeof(t_lswap))))
	{
		ft_putendl("Alloc error");
		error();
	}
	process_stack(&argc, &argv, stack_one);
	read_instructions(cmds);
	result(cmds, stack_one, stack_two);
	return (0);
}

void		result(t_lswap *cmds, t_lswap *stack_one, t_lswap *stack_two)
{
	while (cmds != NULL)
	{
		(cmds->num == 1) ? s_swap(&stack_one, 1, 0) : 1;
		(cmds->num == 2) ? s_swap(&stack_two, 2, 0) : 1;
		(cmds->num == 3) ? s_swap_both(&stack_one, &stack_two, 0) : 1;
		(cmds->num == 4) ? s_push(&stack_one, &stack_two, 1, 0) : 1;
		(cmds->num == 5) ? s_push(&stack_two, &stack_one, 2, 0) : 1;
		(cmds->num == 6) ? s_rotate(&stack_one, 1, 0) : 1;
		(cmds->num == 7) ? s_rotate(&stack_two, 2, 0) : 1;
		(cmds->num == 8) ? s_rotate_both(&stack_one, &stack_two, 0) : 1;
		(cmds->num == 9) ? s_rev_rotate(&stack_one, 1, 0) : 1;
		(cmds->num == 10) ? s_rev_rotate(&stack_two, 2, 0) : 1;
		(cmds->num == 11) ? s_rev_rotate_both(&stack_one, &stack_two, 0) : 1;
		cmds = cmds->next;
	}
	if (stack_two != NULL)
		answer(0);
	while (stack_one->next != NULL)
	{
		if (stack_one->num > stack_one->next->num)
			answer(0);
		stack_one = stack_one->next;
	}
	answer(1);
}

void		answer(_Bool var)
{
	var ? ft_printf("OK\n") : ft_printf("KO\n");
	exit(0);
}
