/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:41 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/08 11:40:08 by gdamion-         ###   ########.fr       */
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
	magic(stack_one, stack_two, cmds);
	result(cmds);
	return (0);
}

void	magic(t_lswap *stack_one, t_lswap *stack_two, t_lswap *cmds)
{

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