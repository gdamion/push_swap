/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:04:35 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/06 11:00:48 by gdamion-         ###   ########.fr       */
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

#endif
