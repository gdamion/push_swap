/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:48 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/07 12:08:11 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

void	process_stack(int *argc, char ***argv, t_lswap *nums);
int		check_intruction(const char *cmd);
int		read_instructions(t_lswap *cmds);
void	result(t_lswap *cmds, t_lswap *stack_one, t_lswap *stack_two);
void	answer(_Bool var);

#endif
