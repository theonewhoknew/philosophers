/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:10:11 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/06 09:12:03 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <stdio.h>

int	alloc_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		philo->philo[i] = (pthread_t *)malloc(sizeof (pthread_t));
		if (philo->philo[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(philo->philo[i]);
				--i;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	alloc_timer(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		philo->timer[i] = (pthread_t *)malloc(sizeof (pthread_t));
		if (philo->timer[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(philo->timer[i]);
				--i;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	alloc_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n)
	{
		philo->mutex[i] = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t));
		if (philo->mutex[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(philo->mutex[i]);
				--i;
			}
			return (1);
		}
		pthread_mutex_init(philo->mutex[i], NULL);
		i++;
	}
	return (0);
}
