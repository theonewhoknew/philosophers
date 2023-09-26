/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:52:36 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/26 13:00:52 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static	void	wait_for_threads(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		pthread_join(*(p->philo[i]), NULL);
		pthread_join(*(p->timer[i]), NULL);
		i++;
	}
	pthread_join(*(p->supervisor), NULL);
}

static void	*timer_routine(void *arg)
{
	static int	id;
	t_philo		*p;

	p = (t_philo *)arg;
	++id;
	timer(p, id);
	return (NULL);
}

static void	*philo_routine(void *arg)
{
	static int	id;
	t_philo		*p;

	p = (t_philo *)arg;
	++id;
	run_philo(p, id);
	return (NULL);
}

void	simulation(t_philo *p)
{
	int	i;

	i = 0;
	p->start_time = get_start_time();
	while (i < p->n)
	{
		pthread_create(p->philo[i], NULL, &philo_routine, p);
		pthread_create(p->timer[i], NULL, &timer_routine, p);
		i++;
		ft_usleep(10);
	}
	p->supervisor = (pthread_t *)malloc(sizeof (pthread_t));
	pthread_create(p->supervisor, NULL, &super_routine, p);
	wait_for_threads(p);
}
