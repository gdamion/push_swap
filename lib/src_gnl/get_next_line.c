/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:34:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 18:46:57 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gnl.h"

// static void		gol_ops_one(char **obj, char **tmp)
// {
// 	if (*obj)
// 		free(*obj);
// 	*obj = *tmp;
// }

// static void		gol_ops_two(int *i, char **content)
// {
// 	while ((*content)[*i] != '\0')
// 	{
// 		if ((*content)[*i] == '\n')
// 			break ;
// 		(*i)++;
// 	}
// }

// static int		get_one_line(char **line, const int fd, char **c, int *e)
// {
// 	char		buf[BUFF_SIZE + 1];
// 	int			rd;
// 	int			i;
// 	char		*tmp;

// 	rd = read(fd, buf, BUFF_SIZE);
// 	buf[rd] = '\0';
// 	if (rd == -1 || !(tmp = ft_strjoin(*c, buf)))
// 		return (-1);
// 	gol_ops_one(c, &tmp);
// 	i = *e + 1;
// 	gol_ops_two(&i, c);
// 	if (rd == 0 && i == *e + 1)
// 		return (0);
// 	if ((*c)[i] == '\n' || ((*c)[i] == '\0' && rd < BUFF_SIZE))
// 	{
// 		if (!(tmp = ft_strsub(*c, *e + 1, i - *e - 1)))
// 			return (-1);
// 		gol_ops_one(line, &tmp);
// 		*e = i;
// 		return (1);
// 	}
// 	return (get_one_line(line, fd, c, e));
// }

// static t_files	*get_correct_el(t_files **start, int fd)
// {
// 	t_files *run;

// 	run = *start;
// 	while (run)
// 	{
// 		if (run->fd == fd)
// 			return (run);
// 		run = run->next;
// 	}
// 	if (!(run = (t_files*)malloc(sizeof(t_files))))
// 		return (NULL);
// 	run->fd = fd;
// 	run->endl = -1;
// 	if (!(run->content = ft_strnew(0)))
// 		return (NULL);
// 	run->next = *start;
// 	*start = run;
// 	return (run);
// }

int				get_next_line(const int fd, char **line)
{
	static t_files	*files;
	t_files			*curr;

	if (fd < 0 || line == NULL)
		return (-1);
	curr = get_correct_el(&files, fd);
	return (get_one_line(line, fd, &(curr->content), &(curr->endl)));
}

char		*got_the_line(char *mem, char **line)
{
	char	*tmp;
	char	*endl;

	if (!(endl = ft_strchr(mem, '\n')))
	{
		endl = mem + ft_strlen(mem);
		tmp = ft_strnew(0);
		*line = ft_strdup(mem);
	}
	else
	{
		tmp = ft_strdup(endl + 1);
		*line = ft_strsub(mem, 0, endl - mem);
	}
	ft_strdel(&mem);
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*mem[10400];
	int			res;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (mem[fd] == NULL)
		mem[fd] = ft_strnew(0);
	while (!ft_strchr(mem[fd], '\n') && (res = read(fd, buf, BUFF_SIZE)))
	{
		buf[res] = '\0';
		tmp = mem[fd];
		mem[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	if (*mem[fd] != '\0')
	{
		mem[fd] = got_the_line(mem[fd], line);
		return (1);
	}
	return (0);
}