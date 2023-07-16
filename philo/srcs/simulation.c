/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:52:36 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/07/16 14:05:08 by theonewhokn      ###   ########.fr       */
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
	while (i < philo->number_of_philo)
	{
		pthread_join(*(philo->philo[i]), NULL);
		pthread_join(*(philo->timer[i]), NULL);
		i++;
	}
	if (philo->opt_argument == 1)
		pthread_join(*(philo->supervisor), NULL);
}

static void	*super_routine(void *arg)
{
	int	i;
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	while (philo->death != 1 && philo->all_have_eaten != 1)
	{
		i = 0;
		while (i < philo->number_of_philo)
		{
			if (philo->eaten_enough[i] == 1)
				i++;
		}
		philo->all_have_eaten = 1;
	}
}

static void	*timer_routine(void *arg)
{
	static int	id;
	t_philo		*philo; 

	philo = (t_philo *)arg;

	++id;
	timer(philo, id);
	//printf("sale de timer routine\n");
}

static void	*philo_routine(void *arg)
{
	static int	id;
	t_philo		*philo;

	philo = (t_philo *)arg;

	++id;
	run(philo, id);
	printf("salimos de philo routine, id %d\n", id);
}

void	simulation(t_philo *philo)
{
	int i;
	i = 0;
	init_mutex(philo);
	//printf("number of philo is %d\n", philo->number_of_philo);
	while (i < philo->number_of_philo)
	{
		philo->philo[i] = (pthread_t*)malloc(sizeof (pthread_t));
		philo->timer[i] = (pthread_t*)malloc(sizeof (pthread_t));
		pthread_create(philo->philo[i], NULL, &philo_routine, philo);
		pthread_create(philo->timer[i], NULL, &timer_routine, philo);
		i++;
		usleep(10);
	}
	if (philo->opt_argument == 1)
	{	
		philo->supervisor = (pthread_t *)malloc(sizeof (pthread_t));
		pthread_create(philo->supervisor, NULL, &super_routine, philo);
	}	
	wait_for_threads(philo);
}