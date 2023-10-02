/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:15:59 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/02 21:05:18 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	release_all(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->n)
	{
		pthread_mutex_unlock(&param->fork[i]);
		i++;
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_f);
	pthread_mutex_unlock(philo->l_f);
}

static void	one_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	print_fork(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->par->m_end);
		if (philo->par->end)
			break ;
		pthread_mutex_unlock(&philo->par->m_end);
	}
}

int	grab_forks(t_philo *philo)
{
	if (philo->par->n == 1)
		one_fork(philo);
	else
	{
		if ((philo->id + 1) % 2)
		{
			pthread_mutex_lock(philo->l_f);
			print_fork(philo);
			pthread_mutex_lock(philo->r_f);
			print_fork(philo);
		}
		else
		{
			pthread_mutex_lock(philo->r_f);
			print_fork(philo);
			pthread_mutex_lock(philo->l_f);
			print_fork(philo);
		}
	}
	return (0);
}
