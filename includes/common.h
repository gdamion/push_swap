/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:04:35 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/06 16:57:34 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../lib/includes/libft.h"
# include "../lib/includes/printf.h"
# include "../lib/includes/gnl.h"

typedef struct		s_lswap
{
	int				num;

	struct s_lswap	*next;
	struct s_lswap	*prev;
}					t_lswap;

void error();
long long ft_atoi_simple_big();

int	s_add(t_list **s, int num);
int	s_swap(t_list **s);
int	s_swap_both(t_list **s1, t_list **s2);
int	s_push(t_list **s);
int	s_push_both(t_list **s1, t_list **s2);
int	s_rotate(t_list **s);
int	s_rotate_both(t_list **s1, t_list **s2);
int	s_rev_rotate(t_list **s);
int	s_rev_rotate_both(t_list **s1, t_list **s2);

#endif
