/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:51:33 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 13:21:45 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	think(t_seat *s)
{
	int	tmp;

	tmp = is_dead(s);
	if (tmp != 0)
		return (tmp);
	tmp = control_read(s);
	if (tmp != 0)
		return (tmp);
	if (s->state != thinking)
	{
		s->state = thinking;
		tmp = print_think(s);
		if (tmp != 0)
			return (tmp);
	}
	if (usleep((useconds_t) UNIT_SLEEP) != 0)
	{
		control_write(s, -1);
		return (-1);
	}
	tmp = is_dead(s);
	if (tmp != 0)
		return (tmp);
	return (0);
}
