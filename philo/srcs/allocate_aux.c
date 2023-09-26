/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:10:11 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 16:28:52 by dtome-pe         ###   ########.fr       */
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
		p->p[i] = (pthread_t *)malloc(sizeof (pthread_t));
		if (p->p[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(p->p[i]);
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
		p->t[i] = (pthread_t *)malloc(sizeof (pthread_t));
		if (p->t[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(p->t[i]);
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
		p->m[i] = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t));
		if (p->m[i] == NULL)
		{
			--i;
			while (i >= 0)
			{
				free(p->m[i]);
				--i;
			}
			return (1);
		}
		pthread_mutex_init(p->m[i], NULL);
		i++;
	}
	return (0);
}
