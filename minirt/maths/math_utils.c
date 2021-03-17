/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:55:54 by mtogbe            #+#    #+#             */
/*   Updated: 2021/03/17 14:55:57 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	min_d(double a, double b)
{
	if (a >= b)
		return (b);
	return (a);
}

double	max_d(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}
