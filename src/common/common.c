/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/07 12:59:19 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void error()
{
	write(2, "Error\n", 6);
	exit (1);
}

//// MY SPECIAL ATOI //// для больших чисел, нужно ведь как-то проверить, что число вписывается в int

long long ft_atoi_simple_big(char *str)
{
	long long res;

	res = 0;
	while (*str != '\0')
	{
		if (*str < '0' && '9' < *str)
			error();
		res = res * 10 + (int)(*str) - 48;
		str++;
	}
	return (res);
}


/////// MAIN OPS ////

int	s_swap(t_lswap **s) //?
{
	t_lswap *run;
	int buf;

	if (!run || !run->next)
		return(0);
	run = *s;
	buf = run->num;
	run->num = run->next->num;
	run->next->num = buf;
	return (1);
}

int	s_swap_both(t_lswap **s1, t_lswap **s2)
{
	int res;

	(!s_swap(s1) || !s_swap(s2)) ?  (res = 0) : (res = 1);
	return (res);
}

int	s_push(t_lswap **s1, t_lswap **s2)//??
{
	t_lswap *run1;
	t_lswap *run2;
	t_lswap *buf;

	if (!run2)
		return(0);
	run1 = *s1;
	run2 = *s2;
	buf = run2;
	run2 = run2->next;
	if (run2 != NULL)
		run2->prev = NULL;
	buf->next = run1;
	if (run1 != NULL)
		run1->prev = buf;
	run1 = buf;
	return (1);
}

int	s_rotate(t_lswap **s)
{
	t_lswap *run;
	int buf_start;
	int buf;

	if (!run || !run->next)
		return(0);
	run = *s;
	buf_start = run->num;
	while(run->next != 0)
	{
		buf = run->num;
		run->num = run->next->num;
		run->next->num = buf;
	}
	run->num = buf_start;
	return (1);
}

int	s_rotate_both(t_lswap **s1, t_lswap **s2)
{
	s_rotate(s1);
	s_rotate(s2);
	return (1);
}

int	s_rev_rotate(t_lswap **s)
{

	return (1);
}

int	s_rev_rotate_both(t_lswap **s1, t_lswap **s2)
{
	s_rev_rotate(s1);
	s_rev_rotate(s2);
	return (1);
}

///////