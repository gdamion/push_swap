/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:20:04 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/12 17:59:16 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

# define BUFF_SIZE 100
# define FD_STORE_SIZE 2000

typedef struct		s_files
{
	char			*content;
	int				fd;
	int				endl;
	struct s_files	next;
}					t_files;

int					get_next_line(const int fd, char **line);
int					get_next_line2(const int fd, char **line);

#endif
