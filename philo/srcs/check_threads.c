/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:14:45 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 17:52:26 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	check_threads(t_param *param, t_philo *philo)
{	
	int	i;

	while (!param->ready)
		continue ;
	while (!param->death)
	{	
		i = -1;
		while (++i < param->n)
		{
			if ((get_time(param) - philo[i].last_meal) > param->teat)
				param->death = 1;
		}
	}
}	