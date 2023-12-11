/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:59:29 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/11 16:53:58 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

int	main(int argc, char *argv[])
{
	t_shared	common;
	t_seat		*seats;

	if (check_args_warn(argc, argv) <= 0)
		return (EXIT_FAILURE);
	if (init_common_warn_clean(&common, argc, argv) < 0)
		return (EXIT_FAILURE);
	if (init_seats_clean(&seats, &common) < 0)
		return (EXIT_FAILURE);
	if (run_simulation(seats, common.total) < 0)
	{
		terminate_common_warn(&common);
		free(seats);
		return (EXIT_FAILURE);
	}
	if (terminate_common_warn(&common) < 0)
		return (EXIT_FAILURE);
	free(seats);
	return (EXIT_SUCCESS);
}
