/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/07/17 09:43:36 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>



void	release_forks(t_philo *philo, int id)
{
	if (id == 1)
	{
		pthread_mutex_unlock(philo->mutex[0]);
		pthread_mutex_unlock(philo->mutex[philo->n - 1]);
	}
	else
	{
		pthread_mutex_unlock(philo->mutex[id - 1]);
		pthread_mutex_unlock(philo->mutex[id - 2]);
	}
}

static int	all_ready(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		if (philo->ready[i] == 1)
			i++;
	}
	philo->start = 1;
	return (1);
}

void	run(t_philo *philo, int id)
{
	long long	time;

	philo->ready[id - 1] = 1;
	while (all_ready(philo) != 1)
		;
	while (philo->death != 1 && philo->all_have_eaten != 1)
	{
		p_think(philo, id);
		p_eat(philo, id);
		p_sleep(philo, id);
	}
}