/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:55:48 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/22 20:09:54 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	check_command(t_stack *stack, char *command)
{
	if (ft_strncmp(command, "pa\n", 3) == 0)
		pa(stack, 0);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		pb(stack, 0);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		rra(stack, 0);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		rrb(stack, 0);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		rrr(stack, 0);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ra(stack, 0);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rb(stack, 0);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rr(stack, 0);
	else if (ft_strncmp(command, "sa\n", 3) == 0)
		sa(stack, 0);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		sb(stack, 0);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ss(stack, 0);
	else
		ft_error();
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	*command;

	if (argc > 1)
	{
		init_stack(&stack, argv);
		command = get_next_line(0);
		while (command)
		{
			check_command(&stack, command);
			free(command);
			command = get_next_line(0);
		}
		if (stack.size_b == 0 && ft_sort_check(stack.top_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free_stack(&stack);
	}
	return (0);
}
