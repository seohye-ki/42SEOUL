/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:57:03 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/16 16:22:15 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int flag)
{
	t_list	*tmp;

	if (stack->size_a > 1)
	{
		tmp = stack->top_a;
		stack->top_a = tmp->next;
		(stack->bottom_a)->next = tmp;
		stack->bottom_a = tmp;
		tmp->next = NULL;
		if (flag == 1)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack *stack, int flag)
{
	t_list	*tmp;

	if (stack->size_b > 1)
	{
		tmp = stack->top_b;
		stack->top_b = tmp->next;
		(stack->bottom_b)->next = tmp;
		stack->bottom_b = tmp;
		tmp->next = NULL;
		if (flag == 1)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack *stack, int flag)
{
	ra(stack, 0);
	rb(stack, 0);
	if ((stack->size_a > 1 || stack->size_b > 1) && flag == 1)
		write(1, "rr\n", 3);
}
