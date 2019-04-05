/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:03:34 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/05 15:13:37 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int main(int argc, char **argv)
{
	t_list	*cmds;
	t_list	*nums;
	
	process_stack(&argc, &argv, &nums); //читаем стэк чисел, проверияем на правильность
	read_instructions(&cmds);
	result(cmds, nums);
	return (0);
}

/////проверка для входного стэка чисел
int		process_stack(int *argc, char ***argv, t_list **nums)
{
	long long num;
	t_list	*nums_check;

	if (*argc < 2)
		error();
	(*nums)->prev = NULL; //у первого элемента нет элемента до него (кэп)
	while (argc > 1)
	{
		if ((*nums)->prev != NULL)
		{
			nums_check = *nums; //записываем данный элемент списка в буфер
			(*nums) = (*nums)->next; //переходим на следующий элемент
			(*nums)->prev = nums_check; //сохраняем связь с предыдущим элементом
		}
		nums_check = *nums;
		num = ft_atoi_ps((*argv)[*argc - 1]);
		if (num < -2147483648 || 2147483647 < num)//проверяем на то, действительно ли число вмещается в int
			error();
		while (nums_check->prev != NULL)//пока не дошли до самого конца стека, проверяем на дубликат
		{
			if (num == nums_check->num)
				error();
			nums_check = nums_check->prev;
		}
		(*nums)->num = (int)num; //пишем нужное число
		argc--;
	}
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

// Ввели команду, нажали ENTER, гнл считал
// rd != 0? тогда применяем команду, проверив на правильность, и ждем следующего нажатия ENTER
// rd == 0? тогда выводим вердикт
void	read_intructions(t_list **cmds)
{
	while()
		!(check_intruction()) ? error() : 1;
}

void	result()
{

}