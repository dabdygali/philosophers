/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:08:07 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 16:06:53 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork(t_resource *fork, t_seat *s)
{
	if (pthread_mutex_lock(&fork->lock) != 0)
	{
		control_write(s, -1);
		return (-1);
	}
	if (fork->status < 0 || fork->status == s->id)
	{
		if (pthread_mutex_unlock(&fork->lock) != 0)
		{
			control_write(s, -1);
			return (-1);
		}
		return (1);
	}
	s->tmp = fork->status;
	fork->status = -1;
	if (pthread_mutex_unlock(&fork->lock) != 0)
	{
		control_write(s, -1);
		return (-1);
	}
	return (0);
}
