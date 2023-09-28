/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:52:36 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/28 12:24:23 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static	void	wait_for_threads(t_param *param, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < param->n)
	{
		pthread_join(philo[i].philo_thread, NULL);
		i++;
	}
}

static void	*routine(void *arg)
{
	static int	id;
	t_philo		*p;

	p = (t_philo *)arg;
	run_philo(p, id);
	return (NULL);
}

void	simulation(t_param *param, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < param->n)
	{
		pthread_create(&philo[i].philo_thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = -1;
	param->start = get_start_time();
	while (++i < param->n)
	{
		philo[i].thread_start = param->start;
		philo[i].last_meal = param->start;
	}
	param->ready = 1;
	check_threads(param, philo);
	wait_for_threads(param, philo);
}
