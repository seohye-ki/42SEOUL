/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:35 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/16 12:16:01 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	linked_list_copy(t_stack *stack)
{
	int		i;
	t_list	*curr;

	stack->arr = (int *)malloc(sizeof(int) * stack->size_a);
	if (stack->arr == NULL)
		exit(1);
	i = 0;
	curr = stack->top_a;
	while (i < stack->size_a)
	{
		stack->arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
	quick_sort(stack->arr, 0, stack->size_a - 1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc > 1)
	{
		init_stack(&stack, argv);
		if (ft_sort_check(stack.top_a))
		{
			ft_free_stack(&stack);
			return (0);
		}
		linked_list_copy(&stack);
		sorting(&stack);
		ft_free_stack(&stack);
	}
	return (0);
}
