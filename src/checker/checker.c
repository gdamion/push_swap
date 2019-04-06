/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/06 11:33:50 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int main(int argc, char **argv)
{
	t_lswap	*cmds;
	t_lswap	*nums;
	
	nums = (t_lswap*)malloc(sizeof(t_list));
	cmds = (t_lswap*)malloc(sizeof(t_list));
	ft_printf("ok0\n");
	process_stack(&argc, &argv, &nums); //читаем стэк чисел, проверияем на правильность
	ft_printf("ok1\n");
	read_instructions(&cmds);
	ft_printf("ok2\n");
	result(cmds, nums);
	return (0);
}

//gcc src/checker/checker.c  src/common/common.c -L. -lft

/////проверка для входного стэка чисел
int		process_stack(int *argc, char ***argv,	t_lswap **nums)
{
	long long num;
	t_lswap	*nums_check;
	int i;

	i = 1;
	if (*argc < 2)
		error();
	ft_printf("ok p1\n");
	(*nums)->prev = NULL; //у первого элемента нет элемента до него (кэп)
	while (i < *argc)
	{
		ft_printf("ok p2\n");
		if (i > 0)
		{
			ft_printf("ok p inner\n");
			nums_check = *nums; //записываем данный элемент списка в буфер
			(*nums) = (*nums)->next; //переходим на следующий элемент
			*nums = (t_lswap*)malloc(sizeof(t_list));
			(*nums)->prev = nums_check; //сохраняем связь с предыдущим элементом
		}
		ft_printf("ok p3\n");
		nums_check = *nums;
		ft_printf("ok p31\n");
		num = ft_atoi_simple_big((*argv)[i]);
		ft_printf("ok p32\n");
		if (num < -2147483648 || 2147483647 < num)//проверяем на то, действительно ли число вмещается в int
			error();
		ft_printf("ok p4\n");
		while (nums_check->prev != NULL)//пока не дошли до самого конца стека, проверяем на дубликат
		{
			if (num == nums_check->num)
				error();
			nums_check = nums_check->prev;
		}
		ft_printf("ok p5\n\n");
		(*nums)->num = (int)num; //пишем нужное число
		argc--;
		i++;
	}
	ft_printf("ok p6\n");
	(*nums)->next = NULL; //замыкаем список
	return (0);
}
///////

int	check_intruction(const char *cmd)
{
	int a;

	a = 0;
	!ft_strcmp(cmd, "sa") ? (a = 1) : 1;
	!ft_strcmp(cmd, "sb") ? (a = 2) : 1;
	!ft_strcmp(cmd, "ss") ? (a = 3) : 1;
	!ft_strcmp(cmd, "pa") ? (a = 4) : 1;
	!ft_strcmp(cmd, "pb") ? (a = 5) : 1;
	!ft_strcmp(cmd, "ra") ? (a = 6) : 1;
	!ft_strcmp(cmd, "rb") ? (a = 7) : 1;
	!ft_strcmp(cmd, "rr") ? (a = 8) : 1;
	!ft_strcmp(cmd, "rra") ? (a = 9) : 1;
	!ft_strcmp(cmd, "rrb") ? (a = 10) : 1;
	!ft_strcmp(cmd, "rrr") ? (a = 11) : 1;
	return (a);
}

void	read_instructions(t_lswap **cmds)
{
	char *buf;
	int cmd_type;
	t_lswap *cmds_buf;

	buf = NULL;
	(*cmds)->prev = NULL;
	while(get_next_line(1, &buf) != 0)
	{
		!(cmd_type = check_intruction(buf)) ? error() : 1;
		if ((*cmds)->prev != NULL)
		{
			cmds_buf = *cmds; //записываем данный элемент списка в буфер
			(*cmds) = (*cmds)->next; //переходим на следующий элемент
			(*cmds)->prev = cmds_buf; //сохраняем связь с предыдущим элементом
		}
		(*cmds)->num = cmd_type; //пишем нужный номер команды
	}
	(*cmds)->next = NULL; //замыкаем список
	while ((*cmds)->prev != NULL) // возвращаемся в начало списка
		*cmds = (*cmds)->prev;
}

void	result(t_lswap *cmds, t_lswap *nums)
{
	while (cmds->next != NULL)
	{
		ft_printf("%d ", cmds->num);
	}
	ft_printf("\n\n");
	while (nums->prev != NULL)
	{
		ft_printf("%d ", nums->num);
	}
}