/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:43:38 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/15 18:40:16 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, int flag)
{
	t_list	*tmp;

	if (stack->size_a > 1)
	{
		tmp = (stack->top_a)->next;
		(stack->top_a)->next = tmp->next;
		tmp->next = stack->top_a;
		stack->top_a = tmp;
		if (stack->size_a < 3)
			stack->bottom_a = ft_lstlast(stack->top_a);
		if (flag == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *stack, int flag)
{
	t_list	*tmp;

	if (stack->size_b > 1)
	{
		tmp = (stack->top_b)->next;
		(stack->top_b)->next = tmp->next;
		tmp->next = stack->top_b;
		stack->top_b = tmp;
		if (stack->size_b < 3)
			stack->bottom_b = ft_lstlast(stack->top_b);
		if (flag == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *stack, int flag)
{
	sa(stack, 0);
	sb(stack, 0);
	if ((stack->size_a > 1 || stack->size_b > 1) && flag == 1)
		write(1, "sb\n", 3);
}
