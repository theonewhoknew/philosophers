/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:59:36 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/02 13:59:40 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int64_t	get_start_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int64_t	get_time(t_param *param)
{
	struct timeval	tv;
	int64_t			time;

	if (gettimeofday(&tv, NULL))
		return (1);
	pthread_mutex_lock(&param->m_start);
	time = ((tv.tv_sec * (uint64_t)1000)
			+ (tv.tv_usec / 1000)) - param->start;
	pthread_mutex_unlock(&param->m_start);
	return (time);
}

int	ft_usleep(int64_t time)
{
	uint64_t	start;

	start = get_start_time();
	while (get_start_time() - start < time)
		usleep(100);
	return (0);
}
