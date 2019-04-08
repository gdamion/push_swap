/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/08 11:13:48 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void		process_stack(int *argc, char ***argv, t_lswap *nums)
{
	long long	num;
	t_lswap		*nums_check;
	int			i;

	i = 1;
	(*argc < 2) ? error() : 1;
	nums->prev = NULL;
	while (i < (*argc))
	{
		(i > 1) ? add_next(&nums) : 1;
		num = ft_atoi_simple_big((*argv)[i]);
		(num < -2147483648 || 2147483647 < num) ? error() : 1;
		if (i > 1)
		{
			nums_check = nums->prev;
			while (nums_check->prev != NULL)
			{
				(num == nums_check->num) ? error() : 1;
				nums_check = nums_check->prev;
			}
		}
		nums->num = (int)num;
		i++;
	}
	nums->next = NULL;
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
	while (get_next_line(1, &buf) != 0)
	{
		!(cmd_type = check_intruction(buf)) ? error() : 1;
		(i > 0) ? add_next(&cmds) : 1;
		cmds->num = cmd_type;
		i++;
		free(buf);
		buf = NULL;
	}
	cmds->next = NULL;
	return (cmd_type);
}

void		add_next(t_lswap **curr)
{
	t_lswap *buf;

	buf = *curr;
	*curr = (*curr)->next;
	if (!(*curr = (t_lswap*)malloc(sizeof(t_list))))
		error();
	buf->next = *curr;
	(*curr)->prev = buf;
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
