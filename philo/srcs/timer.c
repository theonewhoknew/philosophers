/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:59:36 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/29 09:28:13 by theonewhokn      ###   ########.fr       */
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

	if (gettimeofday(&tv, NULL))
		return (1);
	return (((tv.tv_sec * (uint64_t)1000)
			+ (tv.tv_usec / 1000)) - param->start);
}

int	ft_usleep(int64_t time)
{
	uint64_t	start;

	start = get_start_time();
	while (get_start_time() - start < time)
		usleep(time / 10);
	return (0);
}
