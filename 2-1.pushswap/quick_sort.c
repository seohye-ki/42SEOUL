/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:46:32 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/12 15:09:02 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	left;
	int	right;
	int	key;

	if (start >= end)
		return ;
	left = start + 1;
	right = end;
	key = start;
	while (left <= right)
	{
		while (left <= end && arr[left] <= arr[key])
			left++;
		while (right > start && arr[key] <= arr[right])
			right--;
		if (left > right)
			swap(&arr[key], &arr[right]);
		else
			swap(&arr[left], &arr[right]);
	}
	quick_sort(arr, start, right - 1);
	quick_sort(arr, right + 1, end);
}
