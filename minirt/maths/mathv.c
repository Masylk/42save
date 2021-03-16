/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:11:56 by mtogbe            #+#    #+#             */
/*   Updated: 2021/02/22 14:35:33 by mtogbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*freemat(float **mat, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
		free(mat[i--]);
	free(mat);
	return (NULL);
}

double		clamp(double n, double upper, double lower)
{
	return (min(upper, max(x, lower)));
}

double		dot_product(t_vector i, t_vector j)
{
	double	a;
	double	b;
	double	c;

	a = i.x * j.x;
	b = i.y * j.y;
	c = i.z * j.z;
	return (a + b + c);
}

double		get_length(t_vector v)
{
	return (sqrt(dot_product(v, v)));
}

t_vector	normalize(t_vector v)
{
	float	invlen;
	float	len;

	len = get_length(v);
	if (len > 0)
	{
		invlen = 1 / len;
		v.x *= invlen;
		v.y *= invlen;
		v.z *= invlen;
	}
	return (v);
}
