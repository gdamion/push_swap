/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/13 11:05:07 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void		process_stack(int *argc, char ***argv, t_lswap *nums)
{
	long long	num;
	t_lswap		*nums_check;
	int			args;
	int			i;
	char		**curr_arg;

	args = 1;//?
	i = 0;//?
	nums->prev = NULL;
	nums->next = NULL;
	while (args < (*argc))
	{
		curr_arg = ft_strsplit((*argv)[args], ' ');
		while (*curr_arg != NULL)
		{
			num = ft_atoi_simple_big(*curr_arg);//?
			if (num < -2147483648 || 2147483647 < num)
			{
				ft_putendl("Not int");
				error();
			}
			if (i > 0)//?
			{
				add_next(&nums);
				nums_check = nums->prev;
				while (nums_check->prev != NULL)
				{
					if (num == nums_check->num)
					{
						ft_putendl("Duplicate");
						error();
					}
					nums_check = nums_check->prev;
				}
			}
			nums->num = (int)num;
			i++;//?
		//	free(*curr_arg);
			curr_arg++;
		}
		args++;
		//free(curr_arg);
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
	while (get_next_line(0, &buf) != 0)
	{
		//ft_printf("gnl output: %s|\n", buf);
		if (!(cmd_type = check_intruction(buf)))
		{
			ft_putendl("Wrong command");
			error();
		}
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
	if (!((*curr)->next = (t_lswap*)malloc(sizeof(t_lswap))))
	{
		ft_putendl("Add new el error");
		error();
	}
	*curr = (*curr)->next;
	(*curr)->prev = buf;
	(*curr)->next = NULL;
	(*curr)->num = 0;
	(*curr)->step1 = 0;
	(*curr)->step2 = 0;
	(*curr)->vec1 = 0;
	(*curr)->vec2 = 0;
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
	if(!a)
		ft_printf("Comand is: %s|\n", cmd);
	return (a);
}
