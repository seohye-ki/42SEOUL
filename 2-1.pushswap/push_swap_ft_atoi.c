/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:51:19 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/16 16:36:30 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (2147483648);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (2147483648);
		num = num * 10 + *str - '0';
		if (((num * sign) > 2147483647 || (num * sign) < -2147483648))
			return (2147483648);
		str++;
	}
	num = num * sign;
	return (num);
}
