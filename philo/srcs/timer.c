/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:59:36 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/03 13:16:02 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_start_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	get_time(t_param *param)
{
	struct timeval	tv;
	int				time;

	if (gettimeofday(&tv, NULL))
		return (1);
	time = ((tv.tv_sec * (uint64_t)1000)
			+ (tv.tv_usec / 1000)) - param->start;
	return (time);
}

int	ft_usleep(int time, t_param *param)
{
	int	start;

	start = get_time(param);
	while (get_time(param) < start + time)
		usleep(100);
	return (0);
}
