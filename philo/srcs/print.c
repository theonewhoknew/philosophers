/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:12:59 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/03 12:07:34 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

int	print_eat(t_philo *philo)
{
	int	end;

	end = check_death(philo);
	if (end)
		return (1);
	pthread_mutex_lock(&(philo->par->m_print));
	print_aux(get_time(philo->par), philo->id + 1, " is eating");
	pthread_mutex_unlock(&(philo->par->m_print));
	return (0);
}

int	print_sleep(t_philo *philo)
{
	int	end;

	end = check_death(philo);
	if (end)
		return (1);
	pthread_mutex_lock(&(philo->par->m_print));
	print_aux(get_time(philo->par), philo->id + 1, " is sleeping");
	pthread_mutex_unlock(&(philo->par->m_print));
	return (0);
}

int	print_think(t_philo *philo)
{
	int	end;

	end = check_death(philo);
	if (end)
		return (1);
	pthread_mutex_lock(&(philo->par->m_print));
	print_aux(get_time(philo->par), philo->id + 1, " is thinking");
	pthread_mutex_unlock(&(philo->par->m_print));
	return (0);
}

int	print_fork(t_philo *philo)
{
	int	end;

	end = check_death(philo);
	if (end)
		return (1);
	pthread_mutex_lock(&(philo->par->m_print));
	print_aux(get_time(philo->par), philo->id + 1, " has taken a fork");
	pthread_mutex_unlock(&(philo->par->m_print));
	return (0);
}

int	print_end(t_philo *philo, int type)
{
	pthread_mutex_lock(&(philo->par->m_print));
	if (type == DIE)
		print_aux(get_time(philo->par), philo->id + 1, " has died");
	else if (type == ITERS)
		printf("All philosophers have eaten enough!\n");
	pthread_mutex_unlock(&(philo->par->m_print));
	return (0);
}
