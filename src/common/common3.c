/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:37:14 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/08 10:32:58 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void		error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long long	ft_atoi_simple_big(char *str)
{
	long long res;

	res = 0;
	while (*str != '\0')
	{
		if (*str < '0' || '9' < *str)
			error();
		res = res * 10 + (int)(*str) - 48;
		str++;
	}
	return (res);
}

int			s_swap(t_lswap **s)
{
	t_lswap	*run;
	int		buf;

	run = *s;
	if (!run || !run->next)
		return (0);
	buf = run->num;
	run->num = run->next->num;
	run->next->num = buf;
	return (1);
}

int			s_swap_both(t_lswap **s1, t_lswap **s2)
{
	int res;

	res = 1;
	(!s_swap(s1) || !s_swap(s2)) ? (res = 0) : 1;
	return (res);
}
