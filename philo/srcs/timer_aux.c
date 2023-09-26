/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:59:36 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 11:00:20 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

uint64_t	get_start_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

uint64_t	get_time(t_philo *p)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return (((tv.tv_sec * (uint64_t)1000)
			+ (tv.tv_usec / 1000)) - p->start_time);
}

int	ft_usleep(useconds_t time)
{
	uint64_t	start;

	start = get_start_time();
	while (get_start_time() - start < time)
		usleep(time / 10);
	return (0);
}
