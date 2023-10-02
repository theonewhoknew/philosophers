/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:04:42 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/02 21:09:49 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	print_aux(int64_t ms, int id, char *str)
{
	printf("%lu %d %s\n", ms, id, str);
}

int	check_death(t_philo *philo)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&(philo->par->m_end));
	if (philo->par->end)
		end = 1;
	pthread_mutex_unlock(&(philo->par->m_end));
	return (end);
}
