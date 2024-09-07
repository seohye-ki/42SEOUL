/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_find_best.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:51:50 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/12 15:05:10 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_max(t_stack *stack, int *min, int *max)
{
	t_list	*stack_a;

	*min = stack->top_a->value;
	*max = stack->top_a->value;
	stack_a = stack->top_a;
	while (stack_a)
	{
		if (stack_a->value < *min)
			*min = stack_a->value;
		if (stack_a->value > *max)
			*max = stack_a->value;
		stack_a = stack_a->next;
	}
}

static int	find_min_max_index(t_stack *stack, int value, int min, int max)
{
	int		index;
	int		min_max;
	t_list	*stack_a;

	index = 0;
	stack_a = stack->top_a;
	if (value < min)
		min_max = min;
	else
		min_max = max;
	while (stack_a)
	{
		index++;
		if (stack_a->value == min_max)
			break ;
		stack_a = stack_a->next;
	}
	if (index >= stack->size_a / 2)
		index = (stack->size_a - index) * -1;
	if (value < min)
		index--;
	return (index);
}

static int	find_index_a(t_stack *stack, int value)
{
	int		index;
	int		min;
	int		max;
	t_list	*stack_a;

	index = 0;
	find_min_max(stack, &min, &max);
	if (value < min || max < value)
		index = find_min_max_index(stack, value, min, max);
	else
	{
		if (stack->bottom_a->value < value && value < stack->top_a->value)
			return (index);
		stack_a = stack->top_a;
		while (stack_a->next)
		{
			index++;
			if (stack_a->value < value && value < stack_a->next->value)
				break ;
			stack_a = stack_a->next;
		}
		if (index >= stack->size_a / 2)
			index = index - stack->size_a;
	}
	return (index);
}

static void	curr_score(t_list **curr, int score_a, int score_b)
{
	if (score_a < 0)
		(*curr)->score = (score_a * -1);
	else
		(*curr)->score = score_a;
	if (score_b < 0)
		(*curr)->score += (score_b * -1);
	else
		(*curr)->score += score_b;
}

void	find_best(t_stack *stack, int *min_score_a, int *min_score_b)
{
	t_list	*stack_b;
	int		min_score;
	int		score_a;
	int		score_b;
	int		index;

	index = 0;
	stack_b = stack->top_b;
	while (stack_b)
	{
		score_a = find_index_a(stack, stack_b->value);
		if (index >= stack->size_b / 2)
			score_b = index - stack->size_b;
		else
			score_b = index;
		curr_score(&stack_b, score_a, score_b);
		if (index == 0 || stack_b->score < min_score)
		{
			min_score = stack_b->score;
			*min_score_a = score_a;
			*min_score_b = score_b;
		}
		stack_b = stack_b->next;
		index++;
	}
}
