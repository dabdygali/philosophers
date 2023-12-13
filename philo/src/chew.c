/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chew.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:25:01 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 16:15:01 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <sys/time.h>

int	chew(t_seat *s)
{
	struct timeval	t;
	int				tmp;

	tmp = control_read(s);
	if (tmp != 0)
		return (tmp);
	tmp = is_dead(s);
	if (tmp != 0)
		return (tmp);
	if (print_eat(s) < 0)
	{
		control_write(s, -1);
		return (-1);
	}
	s->state = eating;
	if (gettimeofday(&t, NULL))
		return (-1);
	s->prev_meal = (int)((t.tv_sec * 1000) + (t.tv_usec / 1000));
	tmp = safe_sleep(s, s->eat_time);
	if (tmp != 0)
		return (tmp);
	if (s->must_eat > 0)
		s->must_eat--;
	return (0);
}
