/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:52:36 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/07/19 10:21:49 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static	void	wait_for_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		pthread_join(*(philo->philo[i]), NULL);
		pthread_join(*(philo->timer[i]), NULL);
		i++;
	}
	pthread_join(*(philo->supervisor), NULL);
}

static void	*timer_routine(void *arg)
{
	static int	id;
	t_philo		*philo; 

	philo = (t_philo *)arg;

	++id;
	timer(philo, id);
}

static void	*philo_routine(void *arg)
{
	static int	id;
	t_philo		*philo;

	philo = (t_philo *)arg;
	++id;
	run_philo(philo, id);
}

void	simulation(t_philo *philo)
{
	int i;
	i = 0;

	while (i < philo->n)
	{
		pthread_create(philo->philo[i], NULL, &philo_routine, philo);
		pthread_create(philo->timer[i], NULL, &timer_routine, philo);
		i++;
		usleep(10);
	}
	philo->supervisor = (pthread_t *)malloc(sizeof (pthread_t));
	pthread_create(philo->supervisor, NULL, &super_routine, philo);
	wait_for_threads(philo);
}