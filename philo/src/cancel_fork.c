/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:08:07 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 16:07:30 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cancel_fork(t_resource *fork, t_seat *s)
{
	if (pthread_mutex_lock(&fork->lock) != 0)
	{
		control_write(s, -1);
		return (-1);
	}
	if (fork->status < 0)
		fork->status = s->tmp;
	if (pthread_mutex_unlock(&fork->lock) != 0)
	{
		control_write(s, -1);
		return (-1);
	}
	return (0);
}
