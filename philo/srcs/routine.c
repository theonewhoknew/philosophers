/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/03 12:23:16 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

static int	p_eat(t_philo *philo)
{
	int		time;
	int64_t	last;

	if (grab_forks(philo))
		return (1);
	if (print_eat(philo))
		return (1);
	last = get_time(philo->par);
	pthread_mutex_lock(&philo->m_last);
	philo->last = last;
	pthread_mutex_unlock(&philo->m_last);
	ft_usleep(philo->par->teat);
	pthread_mutex_lock(&philo->m_iters);
	philo->iters++;
	pthread_mutex_unlock(&philo->m_iters);
	release_forks(philo, 0);
	return (0);
}

static int	p_sleep_think(t_philo *philo)
{
	if (print_sleep(philo))
		return (1);
	ft_usleep(philo->par->tsleep);
	if (print_think(philo))
		return (1);
	return (0);
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
		if (p_eat(philo))
			return (NULL);
		if (p_sleep_think(philo))
			return (NULL);
	}
	return (NULL);
}
