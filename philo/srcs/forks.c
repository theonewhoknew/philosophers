/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:15:59 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/03 12:24:44 by dtome-pe         ###   ########.fr       */
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

int	release_forks(t_philo *philo, int ret)
{
	pthread_mutex_unlock(philo->r_f);
	pthread_mutex_unlock(philo->l_f);
	return (ret);
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

static int	odd_philo(t_philo *philo)
{
	if ((philo->id + 1) % 2)
	{
		pthread_mutex_lock(philo->l_f);
		if (print_fork(philo))
		{
			pthread_mutex_unlock(philo->l_f);
			return (1);
		}
		pthread_mutex_lock(philo->r_f);
		print_fork(philo);
		if (print_fork(philo))
		{
			pthread_mutex_lock(philo->r_f);
			pthread_mutex_unlock(philo->l_f);
			return (1);
		}
		return (0);
	}
	return (0);
}

int	grab_forks(t_philo *philo)
{
	if (philo->par->n == 1)
		one_fork(philo);
	else
	{
		if ((philo->id + 1) % 2)
		{
			if (odd_philo(philo))
				return (1);
		}
		else
		{
			pthread_mutex_lock(philo->r_f);
			if (print_fork(philo))
			{
				pthread_mutex_unlock(philo->l_f);
				return (1);
			}
			pthread_mutex_lock(philo->l_f);
			if (print_fork(philo))
				return (release_forks(philo, 1));
		}
	}
	return (0);
}
