/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:52:36 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/02 11:54:21 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void	free_all(t_param *param)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&(param->m_end));
	pthread_mutex_destroy(&(param->m_print));
	while (++i < param->n)
	{
		pthread_mutex_destroy(&(param->fork[i]));
		i++;
	}
	free(param->fork);
	free(param->philo);
}

static void	wait_for_threads(t_param *param, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < param->n)
		pthread_join(philo[i].philo_thread, NULL);
}

void	simulation(t_param *param, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < param->n)
	{
		pthread_create(&philo[i].philo_thread, NULL, &routine, &philo[i]);
	}
	i = -1;
	while (++i < param->n)
		philo[i].last = 0;
	param->start = get_start_time();
	pthread_mutex_lock(&param->m_ready);
	param->ready = 1;
	pthread_mutex_unlock(&param->m_ready);
	check_threads(param, philo);
	wait_for_threads(param, philo);
	free_all(param);
}
