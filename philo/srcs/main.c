/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:15 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/26 10:00:21 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_philo	p;

	if (check_args(argc, argv) == 1)
	{
		write(2, "Argument error.\n", 17);
		return (1);
	}
	init_struct(argc, argv, &p);
	if (allocate_struct(&p) == 1)
		return (1);
	simulation(&p);
	free_struct(&p);
}
