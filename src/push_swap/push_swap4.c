/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:57:16 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/15 16:58:43 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		lst_len(t_lswap *lst)
{
	int len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	print_stacks(t_lswap *stack_one, t_lswap *stack_two)
{
	ft_printf("\n\n");
	ft_printf("A ");
	while (stack_one != NULL)
	{
		ft_printf("%d ", stack_one->num);
		stack_one = stack_one->next;
	}
	ft_printf("|\nB ");
	while (stack_two != NULL)
	{
		ft_printf("%d ", stack_two->num);
		stack_two = stack_two->next;
	}
	ft_printf("|\n\n");
}

void	print_stack_info(t_lswap *stack_one, t_lswap *stack_two)
{
	ft_printf("\nA\n");
	while (stack_one)
	{
		ft_printf("%d, %d, %d, %d, %d\n",
		stack_one->num, stack_one->step1, stack_one->step2,
						stack_one->vec1, stack_one->vec2);
		stack_one = stack_one->next;
	}
	ft_printf("\nB\n");
	while (stack_two)
	{
		ft_printf("%d, %d, %d, %d, %d\n",
		stack_two->num, stack_two->step1, stack_two->step2,
						stack_two->vec1, stack_two->vec2);
		stack_two = stack_two->next;
	}
	ft_printf("\n\n");
}

void	el_zerofill(t_lswap *el)
{
	el->prev = NULL;
	el->next = NULL;
	el->num = 0;
	el->step1 = 0;
	el->step2 = 0;
	el->vec1 = 0;
	el->vec2 = 0;
}
