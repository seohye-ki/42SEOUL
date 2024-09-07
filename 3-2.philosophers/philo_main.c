/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:10:17 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/24 14:27:15 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

void	*acting(void *arg)
{
	t_philo_info	*info;
	t_args			*args;

	info = (t_philo_info *)arg;
	args = info->args;
	while (1)
	{
		pthread_mutex_lock(&args->start);
		if (args->start_flag)
		{
			info->last_eat = args->start_time;
			pthread_mutex_unlock(&args->start);
			break ;
		}
		pthread_mutex_unlock(&args->start);
	}
	if (info->id % 2 == 0)
		usleep(args->usleep_time);
	routine(info, args);
	return (0);
}

int	finishing(t_args *args, t_philo_info **info)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		pthread_join((*info)[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < args->philo_num)
	{
		pthread_mutex_destroy(&args->fork[i].mutex);
		pthread_mutex_destroy(&(*info)[i].count);
		i++;
	}
	pthread_mutex_destroy(&args->printf);
	pthread_mutex_destroy(&args->start);
	pthread_mutex_destroy(&args->end);
	free(args->fork);
	free(*info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args			args;
	t_philo_info	*info;
	int				i;

	if (argc != 5 && argc != 6)
		return (1);
	if (philo_init(&args, &info, argc, argv))
		return (1);
	i = 0;
	while (i < args.philo_num)
	{
		pthread_create(&info[i].thread, NULL, acting, &info[i]);
		i++;
	}
	args.start_time = get_time(0);
	pthread_mutex_lock(&args.start);
	args.start_flag = 1;
	pthread_mutex_unlock(&args.start);
	if (args.must_eat)
		monitering(&args, info);
	finishing(&args, &info);
	return (0);
}
