/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:04:35 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/05 12:08:16 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../lib/includes/libft.h"
# include "../lib/includes/printf.h"

typedef struct		s_list
{
	int				num;

	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

#endif
