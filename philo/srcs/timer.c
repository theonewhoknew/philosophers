/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:21:28 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/06 09:54:18 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

uint64_t	get_start_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

uint64_t	get_time(t_philo *philo)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return (((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000)) - philo->start_time);
}

int	ft_usleep(t_philo *philo, useconds_t time)
{
	uint64_t	start;

	start = get_time(philo);
	while (get_time(philo) - start < time)
		usleep(time / 10);
	return (0);
}

static void	philo_died(t_philo *philo, int id)
{
	philo->death = 1;
	printf("%llu %d died\n", get_time(philo), id);
	release_all(philo);
	return ;
}

void	timer(t_philo *philo, int id)
{
	uint64_t	last_meal_time;
	int			elapsed;

	while (philo->start != 1)
		;
	while (philo->death != 1 && philo->all_have_eaten != 1)
	{
		while (philo->eating[id - 1] == 1)
		{
			if (philo->death == 1 || philo->all_have_eaten == 1)
				break ;
		}
		last_meal_time = get_time(philo);
		while (philo->eating[id - 1] == 0 && philo->all_have_eaten != 1
			&& philo->death != 1)
		{
			elapsed = get_time(philo) - last_meal_time;
			if (elapsed > philo->tdie)
				return (philo_died(philo, id));
		}
	}
	release_all(philo);
}
