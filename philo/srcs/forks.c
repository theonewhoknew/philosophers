/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:15:59 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 10:55:57 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	release_all(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		pthread_mutex_unlock(p->m[i]);
		i++;
	}
}

void	release_forks(t_philo *p, int id)
{	
	if (id == 1)
	{	
		pthread_mutex_unlock(p->m[p->n - 1]);
		pthread_mutex_unlock(p->m[0]);
	}
	else
	{
		pthread_mutex_unlock(p->m[id - 2]);
		pthread_mutex_unlock(p->m[id - 1]);
	}
}

static void	one_fork(t_philo *p, int id)
{
	pthread_mutex_lock(p->m[0]);
	printf("%llu %d has taken left fork\n", get_time(p), id);
	while (p->death != 1)
		continue ;
}

static int	philosoper_one(t_philo *p, int id)
{
	pthread_mutex_lock(p->m[p->n - 1]);
/* 	if (p->death == 1 || p->eaten == 1)
		return (1); */
	printf("%llu %d has taken left fork (%d)\n", get_time(p), id, p->n);
	pthread_mutex_lock(p->m[0]);
/* 	if (p->death == 1 || p->eaten == 1)
		return (1); */
	printf("%llu %d has taken right fork (%d)\n", get_time(p), id, id);
	return (0);
}

int	grab_forks(t_philo *p, int id)
{
	if (p->n == 1)
		one_fork(p, id);
	else
	{
		if (id == 1)
			return (philosoper_one(p, id));
		else
		{	
			pthread_mutex_lock(p->m[id - 2]);
	/* 		if (p->death == 1 || p->eaten == 1)
				return (1); */
			printf("%llu %d has taken left fork (%d)\n", get_time(p), id, id - 1);
			pthread_mutex_lock(p->m[id - 1]);
/* 			if (p->death == 1 || p->eaten == 1)
				return (1); */
			printf("%llu %d has taken right fork (%d)\n", get_time(p), id, id);
		}
	}
	return (0);
}
