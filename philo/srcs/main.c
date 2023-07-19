/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:15 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/07/19 10:03:04 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (check_args(argc, argv) == 1)
	{	
		write(2, "Argument error.\n", 17);
		return (1);
	}
	init_struct(argc, argv, &philo);
	if (allocate_struct(&philo) == 1)
		return (1);
	simulation(&philo);
	free_struct(&philo);
}