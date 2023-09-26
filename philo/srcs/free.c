/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:16:33 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 16:27:20 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <stdio.h>

static void	free_mutex(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		pthread_mutex_destroy(p->m[i]);
		i++;
	}
	i = 0;
	while (i < p->n)
	{
		free(p->m[i]);
		i++;
	}
	free(p->m);
}

void	free_philo(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		free(p->p[i]);
		i++;
	}
	free(p->p);
}

void	free_timer(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		free(p->t[i]);
		i++;
	}
	free(p->t);
}

void	free_struct(t_philo *p)
{
	free_philo(p);
	free_timer(p);
	free_mutex(p);
	free(p->eating);
	if (p->opt == 1)
	{
		free(p->s);
		free(p->times_eaten);
		free(p->eaten_enough);
	}
}
