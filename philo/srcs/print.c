/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:12:59 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/02 21:02:24 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	print_eat(t_philo *philo)
{
	int	end;

	end = check_death(philo);
	pthread_mutex_lock(&(philo->par->m_print));
	if (!end)
		print_aux(get_time(philo->par), philo->id + 1, " is eating");
	pthread_mutex_unlock(&(philo->par->m_print));
}

void	print_sleep(t_philo *philo)
{
	int	end;

	end = check_death(philo);
	pthread_mutex_lock(&(philo->par->m_print));
	if (!end)
		print_aux(get_time(philo->par), philo->id + 1, " is sleeping");
	pthread_mutex_unlock(&(philo->par->m_print));
}

void	print_think(t_philo *philo)
{
	int	end;

	end = check_death(philo);
	pthread_mutex_lock(&(philo->par->m_print));
	if (!end)
		print_aux(get_time(philo->par), philo->id + 1, " is thinking");
	pthread_mutex_unlock(&(philo->par->m_print));
}

void	print_fork(t_philo *philo)
{
	int	end;

	end = check_death(philo);
	pthread_mutex_lock(&(philo->par->m_print));
	if (!end)
		print_aux(get_time(philo->par), philo->id + 1, " has taken a fork");
	pthread_mutex_unlock(&(philo->par->m_print));
}

void	print_end(t_philo *philo, int type)
{
	int	end;

	end = check_death(philo);
	pthread_mutex_lock(&(philo->par->m_print));
	if (!end && type == DIE)
		print_aux(get_time(philo->par), philo->id + 1, " has died");
	else if (!end && type == ITERS)
		printf("All philosophers have eaten enough!\n");
	pthread_mutex_unlock(&(philo->par->m_print));
}
