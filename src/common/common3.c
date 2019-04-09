/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:37:14 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/09 18:29:45 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int			s_swap(t_lswap **s, int stack_n, int mode)
{
	t_lswap	*run;
	int		buf;

	if (mode)
		(stack_n == 1) ? ft_putendl("sa") : ft_putendl("sb");
	run = *s;
	if (!run || !run->next)
		return (0);
	buf = run->num;
	run->num = run->next->num;
	run->next->num = buf;
	return (1);
}

int			s_swap_both(t_lswap **s1, t_lswap **s2, int mode)
{
	int res;

	mode ? ft_putendl("ss") : 1;
	res = 1;
	(!s_swap(s1, 1, 0) || !s_swap(s2, 2, 0)) ? (res = 0) : 1;
	return (res);
}

void		error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long long	ft_atoi_simple_big(char *str)
{
	long long res;
	int min;

	res = 0;
	min = 1;
	if (*str == '-')
	{
		min = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || '9' < *str)
			error();
		res = res * 10 + (int)(*str) - 48;
		str++;
	}
	return (res * min);
}
