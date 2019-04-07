/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/07 16:36:34 by gdamion-         ###   ########.fr       */
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

int	s_swap(t_lswap **s)
{
	t_lswap *run;
	int buf;

	run = *s;
	if (!run || !run->next)
		return(0);
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

int	s_push(t_lswap **s1, t_lswap **s2)
{
	t_lswap *buf;

	if (!(*s2))
		return(0);
	buf = *s2;
	*s2 = (*s2)->next;
	if (*s2 != NULL)
		(*s2)->prev = NULL;
	buf->next = *s1;
	if (*s1 != NULL)
		(*s1)->prev = buf;
	*s1 = buf;
	return (1);
}

int	s_rotate(t_lswap **s)
{
	t_lswap *run;
	int buf;
	int buf_start;

	run = *s;
	if (!run || !run->next)
		return(0);
	
	buf_start = run->num;
	while(run->next != NULL)
	{
		buf = run->num;
		run->num = run->next->num;
		run->next->num = buf;
		run = run->next;
	}
	run->num = buf_start;
	return (1);
}

int	s_rotate_both(t_lswap **s1, t_lswap **s2)
{
	int res;

	(!s_rotate(s1) || !s_rotate(s2)) ? (res = 0) : (res = 1);
	return (res);
}

int	s_rev_rotate(t_lswap **s)
{
	t_lswap *run;
	int buf_finish;
	int buf;

	run = *s;
	if (!run || !run->next)
		return(0);
	while (run->next != NULL)
		run = run->next;
	buf_finish = run->num;
	while(run->prev != NULL)
	{
		buf = run->num;
		run->num = run->prev->num;
		run->prev->num = buf;
		run = run->prev;
	}
	run->num = buf_finish;
	return (1);
}

int	s_rev_rotate_both(t_lswap **s1, t_lswap **s2)
{
	int res;

	(!s_rev_rotate(s1) || !s_rev_rotate(s2)) ? (res = 0) : (res = 1);
	return (res);
}

///////