/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:04:24 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/16 12:20:07 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				score;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int				*arr;
	int				size_a;
	struct s_list	*top_a;
	struct s_list	*bottom_a;
	int				size_b;
	struct s_list	*top_b;
	struct s_list	*bottom_b;
}	t_stack;

void		sa(t_stack *stack, int flag);
void		sb(t_stack *stack, int flag);
void		ss(t_stack *stack, int flag);
void		pa(t_stack *stack, int flag);
void		pb(t_stack *stack, int flag);
void		ra(t_stack *stack, int flag);
void		rb(t_stack *stack, int flag);
void		rr(t_stack *stack, int flag);
void		rra(t_stack *stack, int flag);
void		rrb(t_stack *stack, int flag);
void		rrr(t_stack *stack, int flag);
t_list		*ft_lstlast_prev(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, int value);
int			ft_lstsize(t_list *lst);
void		ft_free_arr(char **arr);
void		ft_free_stack(t_stack *stack);
void		ft_error(void);
int			ft_sort_check(t_list *stack);
int			ft_dup_check(t_list *stack, int value);
int			ft_strlen(const char *s);
long long	ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, int n);
void		fill_stack(char **argv, t_stack *stack);
void		init_stack(t_stack *stack, char **argv);
void		quick_sort(int *arr, int start, int end);
void		three_elements(t_stack *stack);
void		five_elements(t_stack *stack);
void		sorting(t_stack *stack);
void		greedy(t_stack *stack);
void		find_best(t_stack *stack, int *min_score_a, int *min_score_b);
void		push_best(t_stack *stack, int *index_a, int *index_b);

#endif