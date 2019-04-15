/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 18:41:47 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int			main(int argc, char **argv)
{
	t_lswap	*cmds;
	t_lswap	*stack_one;
	t_lswap *stack_two;

	(argc == 1) ? exit(0) : 1;
	if (!(stack_one = (t_lswap*)malloc(sizeof(t_lswap)))
		|| !(cmds = (t_lswap*)malloc(sizeof(t_lswap))))
		error();
	process_stack(&argc, &argv, stack_one);
	read_instructions(cmds);
	result(cmds, stack_one, stack_two);
	exit(0);
}

int			read_instructions(t_lswap *cmds)
{
	char	*buf;
	int		cmd_type;
	t_lswap	*cmds_buf;
	int		i;

	i = 0;
	buf = NULL;
	cmds->prev = NULL;
	while (get_next_line(0, &buf) != 0)
	{
		if (!(cmd_type = check_intruction(buf)))
			error();
		(i > 0) ? add_next(&cmds) : 1;
		cmds->num = cmd_type;
		i++;
		free(buf);
		buf = NULL;
	}
	cmds->next = NULL;
	return (cmd_type);
}

int			check_intruction(const char *cmd)
{
	int a;

	a = 0;
	!ft_strcmp(cmd, "sa") ? (a = 1) : 1;
	!ft_strcmp(cmd, "sb") ? (a = 2) : 1;
	!ft_strcmp(cmd, "ss") ? (a = 3) : 1;
	!ft_strcmp(cmd, "pa") ? (a = 4) : 1;
	!ft_strcmp(cmd, "pb") ? (a = 5) : 1;
	!ft_strcmp(cmd, "ra") ? (a = 6) : 1;
	!ft_strcmp(cmd, "rb") ? (a = 7) : 1;
	!ft_strcmp(cmd, "rr") ? (a = 8) : 1;
	!ft_strcmp(cmd, "rra") ? (a = 9) : 1;
	!ft_strcmp(cmd, "rrb") ? (a = 10) : 1;
	!ft_strcmp(cmd, "rrr") ? (a = 11) : 1;
	return (a);
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
