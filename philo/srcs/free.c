/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:16:33 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/06 09:17:33 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <stdio.h>

static void	free_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		pthread_mutex_destroy(philo->mutex[i]);
		i++;
	}
	i = 0;
	while (i < philo->n)
	{
		free(philo->mutex[i]);
		i++;
	}
	free(philo->mutex);
}

void	free_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		free(philo->philo[i]);
		i++;
	}
	free(philo->philo);
}

void	free_timer(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		free(philo->timer[i]);
		i++;
	}
	free(philo->timer);
}

void	free_struct(t_philo *philo)
{
	free_philo(philo);
	free_timer(philo);
	free_mutex(philo);
	free(philo->ready);
	free(philo->eating);
	if (philo->opt == 1)
	{
		free(philo->supervisor);
		free(philo->times_eaten);
		free(philo->eaten_enough);
	}
}
