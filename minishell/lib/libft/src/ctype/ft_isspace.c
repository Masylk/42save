/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:35:33 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/16 15:53:58 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

int	ft_isspace(int c)
{
	return ((c == ' ') || !((c > 13) || (c < 9)));
}
