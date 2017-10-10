/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <janhoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 10:38:13 by janhoon           #+#    #+#             */
/*   Updated: 2017/10/10 11:38:26 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	error_malloc(void)
{
	write(1, "error malloc\n", 13);
	exit(1);
}

void	error_arg(void)
{
	ft_putstr("Incorrect Arguments: Use \'./wolf3d path/to/map\'\n");
	exit(1);
}

void	error_map(void)
{
	ft_putstr("Error processing map\n");
	exit(1);
}
