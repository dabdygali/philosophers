/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_common.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:22:00 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/11 11:53:51 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int	terminate_common_warn(t_shared *common)
{
	int	i;

	if (pthread_mutex_destroy(&common->print.lock) != 0)
		ft_putstr_fd("Failed to destroy mutex \"print\"\n", STDERR_FILENO);
	if (pthread_mutex_destroy(&common->cntrl.lock) != 0)
		ft_putstr_fd("Failed to destroy mutex \"cntrl\"\n", STDERR_FILENO);
	i = 0;
	while (i < common->total)
	{
		if (pthread_mutex_destroy(&common->forks[i].lock) != 0)
			ft_putstr_fd("Failed to destroy mutex lock\n", STDERR_FILENO);
		i++;
	}
	free(common->forks);
	return (0);
}
