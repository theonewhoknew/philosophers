/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:52:36 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/28 10:58:54 by dtome-pe         ###   ########.fr       */
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
		pthread_join(*(p->p[i]), NULL);
		pthread_join(*(p->t[i]), NULL);
		i++;
	}
	pthread_join(*(p->s), NULL);
}

static void	*t_r(void *arg)
{
	static int	id;
	t_philo		*p;

	p = (t_philo *)arg;
	++id;
	timer(p, id);
	return (NULL);
}

static void	*p_r(void *arg)
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
	p->s_t = get_start_time();
	while (i < p->n)
	{
		pthread_create(p->p[i], NULL, &p_r, p);
		pthread_create(p->t[i], NULL, &t_r, p);
		i++;
	}
	p->s = (pthread_t *)malloc(sizeof (pthread_t));
	pthread_create(p->s, NULL, &super_routine, p);
	wait_for_threads(p);
}
