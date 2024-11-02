/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:21:56 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/15 18:44:28 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(char **argv, t_stack *stack)
{
	char		**num_arr;
	long long	value;
	int			i;
	int			j;

	i = 0;
	while (argv[++i])
	{
		num_arr = ft_split(argv[i], ' ');
		if (num_arr == NULL)
			exit(1);
		j = 0;
		while (num_arr[j])
		{
			value = ft_atoi(num_arr[j]);
			if (value > 2147483647 || ft_dup_check(stack->top_a, (int)value))
				ft_error();
			ft_lstadd_back(&(stack->top_a), (int)value);
			j++;
		}
		ft_free_arr(num_arr);
	}
}

void	init_stack(t_stack *stack, char **argv)
{
	stack->arr = NULL;
	stack->top_a = NULL;
	stack->top_b = NULL;
	stack->bottom_b = NULL;
	stack->size_b = 0;
	fill_stack(argv, stack);
	stack->bottom_a = ft_lstlast(stack->top_a);
	stack->size_a = ft_lstsize(stack->top_a);
}
