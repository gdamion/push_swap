/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:34:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 15:53:36 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gnl.h"
#include <stdio.h>
static void		gol_ops_one(char **obj, char **tmp)
{
	if (*obj)
		free(*obj);
	*obj = *tmp;
}

static void		gol_ops_two(int *i, char **content)
{
	while ((*content)[*i] != '\0')
	{
		if ((*content)[*i] == '\n')
			break ;
		(*i)++;
	}
}

// static int		get_one_line(char **line, const int fd, char **c, int *e)
// {
// 	char		buf[BUFF_SIZE + 1];
// 	int			rd;
// 	int			i;
// 	char		*tmp;

// 	while ((rd = read(fd, buf, BUFF_SIZE)))
// 	{
// 		buf[rd] = '\0';
// 		if (rd == -1 || !(tmp = ft_strjoin(*c, buf)))
// 			return (-1);
// 		gol_ops_one(c, &tmp);
// 	}
// 	//printf("CHLEN\n");
// 	i = *e + 1;
// 	gol_ops_two(&i, c);
// 	if ((*c)[i] == '\0')
// 	{
// 		if (!(tmp = ft_strsub(*c, *e + 1, i - *e - 1)))
// 			return (-1);
// 		gol_ops_one(line, &tmp);
// 		*e = i;
// 		//printf("0\n");
// 		return (0);
// 	}
// 	else if ((*c)[i] == '\n')
// 	{
// 		if (!(tmp = ft_strsub(*c, *e + 1, i - *e - 1)))
// 			return (-1);
// 		gol_ops_one(line, &tmp);
// 		*e = i;
// 		//printf("1\n");
// 		return (1);
// 	}
// 	return (get_one_line(line, fd, c, e));
// }

static int	get_one_line(char **line, const int fd, char **c, int *e)
{
	char		buf[BUFF_SIZE + 1];
	int			rd;
	int			i;
	char		*tmp;

	rd = read(fd, buf, BUFF_SIZE);
	buf[rd] = '\0';
	if (rd == -1 || !(tmp = ft_strjoin(*c, buf)))
		return (-1);
	gol_ops_one(c, &tmp);
	// if (rd == 0 && (*e == -1 || (*e != -1 && (*c)[*e] == '\0')))
	// 	return (0);
	i = *e + 1;
	gol_ops_two(&i, c);
	if (rd == 0 && i == *e + 1)
		return (0);
	//printf("content = %s|\n", *c);
	if ((*c)[i] == '\n' || ((*c)[i] == '\0' && rd < BUFF_SIZE))
	{
		if (!(tmp = ft_strsub(*c, *e + 1, i - *e - 1)))
			return (-1);
		gol_ops_one(line, &tmp);
		*e = i;
		//printf("new_endl = %d|\n", *e);
		return (1);
	}
	return (get_one_line(line, fd, c, e));
}

static t_files	*get_correct_el(t_files **start, int fd)
{
	t_files *run;

	run = *start;
	while (run)
	{
		if (run->fd == fd)
			return (run);
		run = run->next;
	}
	if (!(run = (t_files*)malloc(sizeof(t_files))))
		return (NULL);
	run->fd = fd;
	run->endl = -1;
	if (!(run->content = ft_strnew(0)))
		return (NULL);
	run->next = *start;
	*start = run;
	return (run);
}

int				get_next_line(const int fd, char **line)
{
	static t_files	*files;
	t_files			*curr;

	if (fd < 0 || line == NULL)
		return (-1);
	curr = get_correct_el(&files, fd);
	return (get_one_line(line, fd, &(curr->content), &(curr->endl)));
}

// #include <fcntl.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <stdio.h>

// int main()
// {
// 	char *line;

// 	int fd = open("test.txt", O_RDONLY);
// 	int a = 1;
// 	line = NULL;
// 	if (fd != -1)
// 		while(a)
// 		{
// 			a = get_next_line(fd, &line);
// 			printf("out: %d, line: %s\n", a, line);
// 			line = NULL;
// 		}

// 	return (0);
// }