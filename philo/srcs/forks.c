/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:15:59 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/06 10:42:06 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	release_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		pthread_mutex_unlock(philo->mutex[i]);
		i++;
	}
}

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
	printf("%llu %d has released both forks\n", get_time(philo), id);
}

static void	one_fork(t_philo *philo, int id)
{
	pthread_mutex_lock(philo->mutex[0]);
	printf("%llu %d has taken left fork\n", get_time(philo), id);
	while (philo->death != 1)
		;
}

static int	philosoper_one(t_philo *philo, int id)
{
	pthread_mutex_lock(philo->mutex[0]);
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	printf("%llu %d has taken left fork (0)\n", get_time(philo), id);
	pthread_mutex_lock(philo->mutex[philo->n - 1]);
	if (philo->death == 1 || philo->all_have_eaten == 1)
		return (1);
	printf("%llu %d has taken right fork (%d)\n", get_time(philo), id, philo->n - 1);
	return (0);
}

int	grab_forks(t_philo *philo, int id)
{
	if (philo->n == 1)
		one_fork(philo, id);
	else
	{
		if (id == 1)
			return (philosoper_one(philo, id));
		else
		{
			pthread_mutex_lock(philo->mutex[id - 1]);
			if (philo->death == 1 || philo->all_have_eaten == 1)
				return (1);
			printf("%llu %d has taken left fork (%d)\n", get_time(philo), id, id - 1);
			pthread_mutex_lock(philo->mutex[id - 2]);
			if (philo->death == 1 || philo->all_have_eaten == 1)
				return (1);
			printf("%llu %d has taken right fork (%d)\n", get_time(philo), id, id - 2);
		}
	}
	return (0);
}
