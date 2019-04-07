/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/06 22:48:14 by gdamion-         ###   ########.fr       */
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


// //// MAIN OPS ////

int	s_add(t_list **s, int num)
{

	return (0);
}

int	s_swap(t_list **s)
{

	return (0);
}

int	s_swap_both(t_list **s1, t_list **s2)
{
	s_swap(s1);
	s_swap(s2);
	return (0);
}

int	s_push(t_list **s)
{

	return (0);
}

int	s_push_both(t_list **s1, t_list **s2)
{
	s_push(s1);
	s_push(s2);
	return (0);
}

int	s_rotate(t_list **s)
{

	return (0);
}

int	s_rotate_both(t_list **s1, t_list **s2)
{
	s_rotate(s1);
	s_rotate(s2);
	return (0);
}

int	s_rev_rotate(t_list **s)
{

	return (0);
}

int	s_rev_rotate_both(t_list **s1, t_list **s2)
{
	s_rev_rotate(s1);
	s_rev_rotate(s2);
	return (0);
}

// ////
