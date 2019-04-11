/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/11 10:12:50 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void	magic(t_lswap *stack_one, t_lswap *stack_two, int len);
void	print_stacks(t_lswap *stack_one, t_lswap *stack_two);
void	print_stack_info(t_lswap *stack_one, t_lswap *stack_two);
int		drop_to_b(t_lswap **stack_one, t_lswap **stack_two, int len);
void	predict_all(t_lswap *s1, t_lswap *s2, int len_a, int len_b);
void	predict_in_a(t_lswap *s1, t_lswap *s2, int buf, int len_a);
void	find_best(t_lswap **opt, t_lswap *s2);
void	exec(t_lswap **stack_one, t_lswap **stack_two, t_lswap *opt);
void	final_moves(t_lswap **s1, int min, int len_a);
int		lst_len(t_lswap	*lst);
void	el_zerofill(t_lswap *el);
int		ordered(t_lswap	*s, int len);

#endif
