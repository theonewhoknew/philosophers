/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:10:11 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 10:03:25 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <stdio.h>

int	alloc_philo(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		p->philo[i] = (pthread_t *)malloc(sizeof (pthread_t));
		if (p->philo[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(p->philo[i]);
				--i;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	alloc_timer(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		p->timer[i] = (pthread_t *)malloc(sizeof (pthread_t));
		if (p->timer[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(p->timer[i]);
				--i;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	alloc_mutex(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		p->mutex[i] = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t));
		if (p->mutex[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(p->mutex[i]);
				--i;
			}
			return (1);
		}
		pthread_mutex_init(p->mutex[i], NULL);
		i++;
	}
	return (0);
}
