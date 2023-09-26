/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:12:14 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 13:14:04 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <stdlib.h>

static int	alloc_error(t_philo *p)
{
	if (p->philo != NULL)
		free(p->philo);
	if (p->timer != NULL)
		free(p->timer);
	if (p->mutex != NULL)
		free(p->mutex);
	if (p->eating != NULL)
		free(p->eating);
	if (p->opt == 1)
	{
		if (p->times_eaten != NULL)
			free(p->times_eaten);
		if (p->eaten_enough != NULL)
			free(p->eaten_enough);
	}
	return (1);
}

static int	alloc_opt(t_philo *p)
{
	if (p->opt == 1)
	{
		p->times_eaten = (int *)malloc(sizeof (int) * p->n);
		if (p->times_eaten == NULL)
			return (1);
		fill_times_eaten(p);
		p->eaten_enough = (int *)malloc(sizeof (int) * p->n);
		if (p->eaten_enough == NULL)
			return (1);
		fill_eaten_enough(p);
		return (0);
	}
	else
		return (0);
}

static int	philo_timer_mutex(t_philo *p)
{
	if (alloc_philo(p) == 1)
		return (1);
	if (alloc_timer(p) == 1)
	{
		free_philo(p);
		return (1);
	}
	if (alloc_mutex(p) == 1)
	{
		free_philo(p);
		free_timer(p);
		return (1);
	}
	return (0);
}

int	allocate_struct(t_philo *p)
{
	p->philo = (pthread_t **)malloc(p->n * sizeof (pthread_t *));
	if (p->philo == NULL)
		return (alloc_error(p));
	p->timer = (pthread_t **)malloc(p->n * sizeof (pthread_t *));
	if (p->timer == NULL)
		return (alloc_error(p));
	p->mutex = (pthread_mutex_t **)malloc
		(p->n * sizeof (pthread_mutex_t *));
	if (p->mutex == NULL)
		return (alloc_error(p));
	p->eating = (int *)malloc(sizeof (int) * p->n);
	if (p->eating == NULL)
		return (alloc_error(p));
	fill_eating(p);
	if (alloc_opt(p) == 1)
		return (alloc_error(p));
	if (philo_timer_mutex(p) == 1)
		return (alloc_error(p));
	return (0);
}
