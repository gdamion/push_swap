/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:48 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/06 10:59:23 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

int		process_stack(int *argc, char ***argv, t_lswap **nums);
int		check_intruction(const char *cmd);
void	read_instructions(t_lswap **cmds);
void	result(t_lswap *cmds, t_lswap *nums);

#endif
