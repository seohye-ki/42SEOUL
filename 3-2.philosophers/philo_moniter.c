/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_moniter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:17:42 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/24 13:51:21 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

int	check_end(t_philo_info *info, t_args *args)
{
	pthread_mutex_lock(&args->end);
	if (args->end_flag)
	{
		info->last_eat = args->start_time;
		pthread_mutex_unlock(&args->end);
		return (1);
	}
	pthread_mutex_unlock(&args->end);
	if (args->alive_time < get_time(info->last_eat))
	{
		pthread_mutex_lock(&args->end);
		if (args->end_flag == 0)
		{
			pthread_mutex_lock(&args->printf);
			printf("%ld %d %s\n", get_time(args->start_time), info->id, "died");
			pthread_mutex_unlock(&args->printf);
			args->end_flag = 1;
		}
		pthread_mutex_unlock(&args->end);
		return (1);
	}
	return (0);
}

static int	all_philo_eat(t_args *args, int *i, int *eat_philo)
{
	if (*eat_philo == args->philo_num)
	{
		pthread_mutex_lock(&args->end);
		args->end_flag = 1;
		pthread_mutex_unlock(&args->end);
		return (1);
	}
	*i = 0;
	*eat_philo = 0;
	return (0);
}

int	monitering(t_args *args, t_philo_info *info)
{
	int	i;
	int	eat_philo;

	i = 0;
	eat_philo = 0;
	while (1)
	{
		pthread_mutex_lock(&args->end);
		if (args->end_flag)
		{
			pthread_mutex_unlock(&args->end);
			break ;
		}
		pthread_mutex_unlock(&args->end);
		pthread_mutex_lock(&info[i].count);
		if (info[i].eat_count >= args->must_eat)
			eat_philo++;
		pthread_mutex_unlock(&info[i].count);
		i++;
		if (i == args->philo_num)
			if (all_philo_eat(args, &i, &eat_philo))
				return (0);
		usleep(50);
	}
	return (0);
}
