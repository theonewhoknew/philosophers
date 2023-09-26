/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:19:27 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 13:00:07 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	*super_routine(void *arg)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->opt == 1)
	{
		while (p->death != 1 && p->all_have_eaten != 1)
		{
			i = 0;
			while (i < p->n && p->death != 1)
			{
				if (p->eaten_enough[i] == 1)
				{
					++i;
				}
			}
			p->all_have_eaten = 1;
		}
	}
	return (NULL);
}
