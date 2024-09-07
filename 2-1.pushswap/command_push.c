/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:52:58 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/15 18:29:13 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack, int flag)
{
	t_list	*tmp;

	if (stack->top_b != NULL)
	{
		tmp = stack->top_b;
		if (stack->top_a == NULL)
		{
			stack->top_b = tmp->next;
			stack->top_a = tmp;
			(stack->top_a)->next = NULL;
			stack->bottom_a = ft_lstlast(stack->top_a);
			stack->bottom_b = ft_lstlast(stack->top_b);
		}
		else
		{
			stack->top_b = tmp->next;
			tmp->next = stack->top_a;
			stack->top_a = tmp;
		}
		(stack->size_b)--;
		(stack->size_a)++;
		if (flag == 1)
			write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack, int flag)
{
	t_list	*tmp;

	if (stack->top_a != NULL)
	{
		tmp = stack->top_a;
		if (stack->top_b == NULL)
		{
			stack->top_a = tmp->next;
			stack->top_b = tmp;
			(stack->top_b)->next = NULL;
			stack->bottom_b = ft_lstlast(stack->top_b);
			stack->bottom_a = ft_lstlast(stack->top_a);
		}
		else
		{
			stack->top_a = tmp->next;
			tmp->next = stack->top_b;
			stack->top_b = tmp;
		}
		(stack->size_a)--;
		(stack->size_b)++;
		if (flag == 1)
			write(1, "pb\n", 3);
	}
}
