/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:59:29 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/23 16:08:24 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

int	main(int argc, char *argv[])
{
	if (check_args_warn(argc, argv) <= 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
