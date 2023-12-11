/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_warn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:50:22 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/11 16:21:25 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include "philo.h"

int	unlock_warn(pthread_mutex_t *mutex, pthread_mutex_t *print)
{
	int	i;

	i = pthread_mutex_unlock(mutex);
	if (i != 0)
	{
		pthread_mutex_lock(print);
		ft_putstr_fd("Failed to unlock mutex\n", STDERR_FILENO);
		pthread_mutex_unlock(print);
		return (i);
	}
	return (0);
}
