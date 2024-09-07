/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:30:18 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/24 14:24:40 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

long	ft_atol(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (str == 0)
		return (-1);
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
		if (*str < '0' || '9' < *str)
			return (-1);
	}
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (-1);
		num = num * 10 + *str++ - '0';
		if (num * sign < 0 || num * sign > 2147483647)
			return (-1);
	}
	return (num);
}

long	get_time(long t)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - t);
}

int	ft_usleep(t_philo_info *info, t_args *args, long cur, long act_time)
{
	while (check_end(info, args) == 0)
	{
		if (get_time(cur) >= act_time)
			return (0);
		usleep(args->usleep_time);
	}
	return (1);
}

void	ft_printf(t_philo_info *info, t_args *args, char *msg)
{
	pthread_mutex_lock(&args->printf);
	pthread_mutex_lock(&args->end);
	if (args->end_flag == 0)
		printf("%ld %d %s\n", get_time(args->start_time), info->id, msg);
	pthread_mutex_unlock(&args->end);
	pthread_mutex_unlock(&args->printf);
}
