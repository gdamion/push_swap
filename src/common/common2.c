/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:29:54 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/07 17:30:07 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int			s_push(t_lswap **s1, t_lswap **s2)
{
	t_lswap *buf;

	if (!(*s2))
		return (0);
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

int			s_rotate(t_lswap **s)
{
	t_lswap	*run;
	int		buf;
	int		buf_start;

	run = *s;
	if (!run || !run->next)
		return (0);
	buf_start = run->num;
	while (run->next != NULL)
	{
		buf = run->num;
		run->num = run->next->num;
		run->next->num = buf;
		run = run->next;
	}
	run->num = buf_start;
	return (1);
}

int			s_rotate_both(t_lswap **s1, t_lswap **s2)
{
	int res;

	res = 1;
	(!s_rotate(s1) || !s_rotate(s2)) ? (res = 0) : 1;
	return (res);
}

int			s_rev_rotate(t_lswap **s)
{
	t_lswap	*run;
	int		buf_finish;
	int		buf;

	run = *s;
	if (!run || !run->next)
		return (0);
	while (run->next != NULL)
		run = run->next;
	buf_finish = run->num;
	while (run->prev != NULL)
	{
		buf = run->num;
		run->num = run->prev->num;
		run->prev->num = buf;
		run = run->prev;
	}
	run->num = buf_finish;
	return (1);
}

int			s_rev_rotate_both(t_lswap **s1, t_lswap **s2)
{
	int res;

	res = 1;
	(!s_rev_rotate(s1) || !s_rev_rotate(s2)) ? (res = 0) : 1;
	return (res);
}
