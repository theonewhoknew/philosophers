/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:04:42 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/03 11:43:38 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	print_aux(int64_t ms, int id, char *str)
{
	printf("%lld %d %s\n", ms, id, str);
}

int	check_death(t_philo *philo)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&(philo->par->m_end));
	if (philo->par->end == 1)
		end = 1;
	pthread_mutex_unlock(&(philo->par->m_end));
	return (end);
}
