/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:34:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/13 12:18:35 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gnl.h"

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static void	gol_ops_one(char **obj, char **tmp)
{
	free(*obj);
	*obj = *tmp;
}

static void	gol_ops_two(int *i, char **content)
{
	while ((*content)[*i] != '\0')
	{
		if ((*content)[*i] == '\n')
			break ;
		(*i)++;
	}
}
// не читается 1-й символ
static int	get_one_line(char **line, const int fd, char **c, int *e)
{
	char		buf[BUFF_SIZE + 1];
	int			rd;
	int			i;
	char		*tmp;

	ft_bzero(buf, BUFF_SIZE + 1);
	rd = read(fd, buf, BUFF_SIZE);

	if (rd == -1 || !(tmp = ft_strjoin(*c, buf)))
		return (-1);
	printf("buf = %s|\n", buf);
	gol_ops_one(c, &tmp);
	i = *e + 1;
	if (((*e == -1 && (*c)[i] == '\0')) || (*e != -1 && (*c)[*e] == '\0'))
		return (0);
	gol_ops_two(&i, c);
	if (rd == 0 && (i == *e + 1) && (*c)[i] == '\0')
		return (0);
	if (!(tmp = ft_strsub(*c, *e + 1, i - *e - 1)))
		return (-1);
	gol_ops_one(line, &tmp);
	if ((*c)[i] == '\n' || ((*c)[i] == '\0' && (rd == 0 || rd < BUFF_SIZE)))
	{
		*e = i;
		return (1);
	}
	return (get_one_line(line, fd, c, e));
}

// int			get_next_line(const int fd, char **line)
// {
// 	static t_files	files[FD_STORE_SIZE];

// 	if (fd < 0 || !line || BUFF_SIZE < 1)
// 		return (-1);
// 	if (!(files[fd].content))
// 	{
// 		if (!(files[fd].content = ft_strnew(0)))
// 			return (-1);
// 		files[fd].endl = -1;
// 	}
// 	return (get_one_line(line, fd, &files[fd].content, &files[fd].endl));
// }

static t_files	*get_correct_el(t_files	**start, int fd)
{
	t_files	*run;

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
	run->endl = 0;
	if (!(run->content = ft_strnew(0)))
		return (NULL);
	run->next = *start;
	*start = run;
	return (run);
}

int			get_next_line(const int fd, char **line)
{
	static t_files	*files;
	t_files			*curr;

	if (fd < 0 || line == NULL)
		return (-1);
	curr = get_correct_el(&files, fd);

	return (get_one_line(line, fd, &(curr->content), &(curr->endl)));
}



int main()
{
	char *test;
	int a;

	int rd = open("test.txt", O_RDONLY);
		//printf("%d\n", rd);
	int i = 0;

	while(a)
	{
		test = NULL;
		a = get_next_line(rd, &test);
		printf("gnl out = %d| string = %s|\n", a, test);
		i++;
	}
	return (0);
}

//strchr
//strlen
//strdup
//strsub
//strjoin
//strdel
//strnew
