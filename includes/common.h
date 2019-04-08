/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:04:35 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/07 17:57:38 by gdamion-         ###   ########.fr       */
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

void				error();
long long			ft_atoi_simple_big();

void				add_next(t_lswap **curr);
void				process_stack(int *argc, char ***argv, t_lswap *nums);
int					check_intruction(const char *cmd);
int					read_instructions(t_lswap *cmds);

int					s_swap(t_lswap **s);
int					s_swap_both(t_lswap **s1, t_lswap **s2);
int					s_push(t_lswap **s1, t_lswap **s2);
int					s_rotate(t_lswap **s);
int					s_rotate_both(t_lswap **s1, t_lswap **s2);
int					s_rev_rotate(t_lswap **s);
int					s_rev_rotate_both(t_lswap **s1, t_lswap **s2);

#endif
