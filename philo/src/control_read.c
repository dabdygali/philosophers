/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:30:55 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/12 16:27:08 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	control_read(t_seat *seat)
{
	int	status;

	if (lock_warn(&seat->cntrl->lock, &seat->print->lock) != 0)
	{
		seat->cntrl->status = -1;
		return (-1);
	}
	status = seat->cntrl->status;
	if (unlock_warn(&seat->cntrl->lock, &seat->print->lock) != 0)
		return (-1);
	if (status != 0)
		return (1);
	return (0);
}
