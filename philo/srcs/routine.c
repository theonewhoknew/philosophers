/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/29 10:50:20 by theonewhokn      ###   ########.fr       */
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
	print_state(philo, EAT);
	philo->last_meal = get_time(philo->par);
	ft_usleep(philo->par->teat);
	philo->iters++;
	release_forks(philo);
}

static void	p_sleep_think(t_philo *philo)
{
	print_state(philo, SLEEP);
	ft_usleep(philo->par->tsleep);
	print_state(philo, THINK);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (!philo->par->ready)
		continue ;
	if ((philo->id + 1) % 2 != 0)
		ft_usleep(philo->par->teat * 0.9 + 1);
	while (philo->par->end != 1)
	{
		p_eat(philo);
		p_sleep_think(philo);
	}
	return (NULL);
}
