/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:14:45 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/29 10:31:29 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	check_threads(t_param *param, t_philo *philo)
{
	int	i;

	while (!param->ready)
		continue ;
	while (!param->end)
	{
		i = -1;
		while (++i < param->n)
		{
			if ((get_time(param) - philo[i].last_meal) > param->tdie)
			{
				print_state(&philo[i], DIE);
				pthread_mutex_lock(&(param->m_end));
				param->end = 1;
				pthread_mutex_unlock(&(param->m_end));
			}
			else if (philo[i].iters > param->max_iters)
			{
				print_state(&philo[i], ITERS);
				pthread_mutex_lock(&(param->m_end));
				param->end = 1;
				pthread_mutex_unlock(&(param->m_end));
			}
		}
	}
}
