/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 13:40:52 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int			process_stack(int *argc, char ***argv, t_lswap *nums)
{
	long long	num;
	t_lswap		*nums_check;
	int			args;
	int			i;
	char		**curr_arg;
	int			flag;

	flag = 0;
	args = 1;
	i = 0;
	nums->prev = NULL;
	nums->next = NULL;
	while (args < (*argc))
	{
		curr_arg = ft_strsplit((*argv)[args], ' ');
		while (*curr_arg != NULL)
		{
			if (!ft_strcmp(*curr_arg, "-v"))
			{
				flag = 1;
				continue;
			}
			num = ft_atoi_simple_big(*curr_arg);
			if (num < -2147483648 || 2147483647 < num)
				error();
			if (i > 0)
			{
				add_next(&nums);
				nums_check = nums->prev;
				while (nums_check->prev != NULL)
				{
					if (num == nums_check->num)
						error();
					nums_check = nums_check->prev;
				}
			}
			nums->num = (int)num;
			i++;
			curr_arg++;
		}
		args++;
	}
	nums->next = NULL;
	return (flag);
}



void		add_next(t_lswap **curr)
{
	t_lswap *buf;

	buf = *curr;
	if (!((*curr)->next = (t_lswap*)malloc(sizeof(t_lswap))))
		error();
	*curr = (*curr)->next;
	(*curr)->prev = buf;
	(*curr)->next = NULL;
	(*curr)->num = 0;
	(*curr)->step1 = 0;
	(*curr)->step2 = 0;
	(*curr)->vec1 = 0;
	(*curr)->vec2 = 0;
}
