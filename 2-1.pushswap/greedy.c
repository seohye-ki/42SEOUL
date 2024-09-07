/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:10:53 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/12 18:46:27 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_a_to_b(t_stack *stack)
{
	int	pivot_large;
	int	pivot_small;
	int	first_value;

	pivot_small = stack->size_a / 3;
	pivot_large = (stack->size_a / 3) * 2;
	first_value = stack->bottom_a->value;
	while (1)
	{
		if (pivot_large < stack->top_a->value)
			ra(stack, 1);
		else if (pivot_small < stack->top_a->value)
			pb(stack, 1);
		else
		{
			pb(stack, 1);
			rb(stack, 1);
		}
		if (stack->top_a->value == first_value)
			break ;
	}
	while (stack->size_a > 3)
		pb(stack, 1);
	three_elements(stack);
}

void	make_a_top_zero(t_stack *stack)
{
	int		index_zero;
	t_list	*curr;

	index_zero = 0;
	curr = stack->top_a;
	while (curr->value != 0)
	{
		index_zero++;
		curr = curr->next;
	}
	if (index_zero < stack->size_a / 2)
	{
		while (stack->top_a->value != 0)
			ra(stack, 1);
	}
	else
	{
		while (stack->top_a->value != 0)
			rra(stack, 1);
	}
}

void	greedy(t_stack *stack)
{
	int		index_a;
	int		index_b;

	push_all_a_to_b(stack);
	while (stack->size_b > 0)
	{
		index_a = 0;
		index_b = 0;
		find_best(stack, &index_a, &index_b);
		push_best(stack, &index_a, &index_b);
	}
	make_a_top_zero(stack);
}
