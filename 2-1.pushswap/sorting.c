/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:06:58 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/15 19:00:17 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chage_value_to_index(t_stack *stack)
{
	int		i;
	t_list	*curr;

	curr = stack->top_a;
	while (curr)
	{
		i = 0;
		while (1)
		{
			if (curr->value == stack->arr[i])
				break ;
			i++;
		}
		curr->value = i;
		curr = curr->next;
	}
}

void	three_elements(t_stack *stack)
{
	if (ft_sort_check(stack->top_a))
		return ;
	if (stack->top_a->value > stack->top_a->next->value)
	{
		if (stack->top_a->value < stack->bottom_a->value)
			sa(stack, 1);
		else if (stack->top_a->next->value < stack->bottom_a->value)
			ra(stack, 1);
		else
		{
			sa(stack, 1);
			rra(stack, 1);
		}
	}
	else
	{
		rra(stack, 1);
		if (stack->top_a->value > stack->top_a->next->value)
			sa(stack, 1);
	}
}

void	five_elements(t_stack *stack)
{
	int		pivot;

	if (stack->size_a % 2 == 1)
		pivot = stack->size_a / 2;
	else
		pivot = (stack->size_a / 2) - 1;
	while (stack->size_a > 3)
	{
		if (stack->top_a->value < pivot)
			pb(stack, 1);
		else
			ra(stack, 1);
	}
	three_elements(stack);
	if (stack->size_b > 1)
	{
		if (stack->top_b->value < stack->top_b->next->value)
			sb(stack, 1);
	}
	while (stack->size_b > 0)
		pa(stack, 1);
}

void	sorting(t_stack *stack)
{
	chage_value_to_index(stack);
	if (stack->size_a == 2)
		sa(stack, 1);
	else if (stack->size_a == 3)
		three_elements(stack);
	else if (stack->size_a == 4 || stack->size_a == 5)
		five_elements(stack);
	else
		greedy(stack);
}
