/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/02 21:03:35 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

static void	p_eat(t_philo *philo)
{
	int		time;
	int64_t	last;

	grab_forks(philo);
	print_eat(philo);
	last = get_time(philo->par);
	pthread_mutex_lock(&philo->m_last);
	philo->last = last;
	pthread_mutex_unlock(&philo->m_last);
	ft_usleep(philo->par->teat);
	pthread_mutex_lock(&philo->m_iters);
	philo->iters++;
	pthread_mutex_unlock(&philo->m_iters);
	release_forks(philo);
}

static void	p_sleep_think(t_philo *philo)
{
	print_sleep(philo);
	ft_usleep(philo->par->tsleep);
	print_think(philo);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	int			end;

	philo = (t_philo *)arg;
	philo->ready = 0;
	while (!philo->ready)
	{
		pthread_mutex_lock(&philo->par->m_ready);
		if (philo->par->ready)
			philo->ready = 1;
		pthread_mutex_unlock(&philo->par->m_ready);
	}
	if ((philo->id + 1) % 2)
		ft_usleep(philo->par->teat * 0.9 + 1);
	while (1)
	{
		pthread_mutex_lock(&philo->par->m_end);
		if (philo->par->end)
			break ;
		pthread_mutex_unlock(&philo->par->m_end);
		p_eat(philo);
		p_sleep_think(philo);
	}
	pthread_mutex_unlock(&philo->par->m_end);
	return (NULL);
}
