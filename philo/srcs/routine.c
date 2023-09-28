/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/28 17:45:37 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

static void	p_eat(t_philo *philo)
{
	grab_forks(philo);
	printf("%llu %d is eating\n", get_time(philo->par), philo->id + 1);
	ft_usleep(philo->par->teat);
	philo->iters++;
	release_forks(philo);
}

static void	p_sleep_think(t_philo *philo)
{
	printf("%llu %d is sleeping\n", get_time(philo->par), philo->id + 1);
	ft_usleep(philo->par->tsleep);
	printf("%llu %d is thinking\n", get_time(philo->par), philo->id + 1);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	printf("philo %d created\n", philo->id + 1);
	while (!philo->par->ready)
		continue ;
	if (philo->id + 1 % 2 != 0)
		ft_usleep(philo->par->teat * 0.9 + 1);
	while (philo->par->death != 1 && philo->par->eaten != 1)
	{
		p_eat(philo);
		p_sleep_think(philo);
	}
	return (NULL);
}
