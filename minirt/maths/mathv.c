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

void	*freemat(float **mat, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
		free(mat[i--]);
	free(mat);
	return (NULL);
}

//can obtain inverse on square matrix to get back from point B to A
//multiply a matrix by its inverse gives the identity matrix
/*float	**transpose(float ***mat, int size)
{
	float	**transmat;
	int		i;
	int		j;

	i = 0;
	transmat = malloc(sizeof(float *) * size);
	if (!transmat)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			transmat[i] = malloc(sizeof(float) * size);
			if (!(transmat[i]))
				return (freemat(transmat, i));
			transmat[i][j] = (*mat)[j++][i];
		}
		i++;
	}
	free(*mat);
	*mat = transmat;
	return (transmat);
}

float	get_radians(float angle)
{
	return ((M_PI / 180) * angle);
}

double	get_tan(double opp, double adj)
{
	return (opp / adj);
}

double	get_cos(double adj, double hyp)
{
	return (adj / hyp);
}

double	get_sin(double opp, double hyp)
{
	return (opp / hyp);
}

double	get_hyp(double adj, double opp)
{
	return (sqrt(adj) + sqrt(opp));
}

t_vector	spher_to_cart(t_vector v, float theta, float phi)
{
	t_vector	res;

	res.x = cos(phi) * sin(theta);
	res.y = sin(phi) * sin(theta);
	res.z = cos(theta);
	return (res);
}

float	get_phi_cart(t_vector v)
{
	return (atan2(v.y / v.x));
}

double	min(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	clamp(double n, double upper, double lower)
{
	return (min(upper, max(x, lower)));
}

float	get_phi_spher(t_vector v)
{
	p = atan2(v.y, v.x);
	if (p < 0)
		p = p + 2 * M_PI;
	return (p);
}*/
