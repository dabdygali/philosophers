/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:26:28 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 16:01:20 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

int	is_dead(t_seat *s)
{
	struct timeval	t;
	int				tmp;

	if (gettimeofday(&t, NULL) != 0)
	{
		control_write(s, -1);
		return (-1);
	}
	tmp = (int)((t.tv_sec * 1000) + (t.tv_usec / 1000)) - s->prev_meal;
	if (tmp > s->die_time || control_read(s))
	{
		tmp = control_read(s);
		if (tmp != 0)
			return (tmp);
		if (print_dead(s) < 0)
		{
			control_write(s, -1);
			return (-1);
		}
		if (control_write(s, 1) < 0)
			return (-1);
		return (1);
	}
	return (0);
}
