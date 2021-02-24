#include "minirt.h"


t_vector	cross_product(t_vector i, t_vector j)
{
	t_vector	result;

	result.x = i.y * j.z - i.z * j.y;
	result.y = i.z * j.x - i.x * j.z;
	result.z = i.x * j.y - i.y * j.x;
	return (result);
}

t_vector	add(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vector	sub(t_vector a, t_vector b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vector	mul(t_vector a, t_vector b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_vector	mul_n(t_vector v, double n)
{
	v.x *= n;
	v.y *= n;
	v.z *= n;
	return (v);
}

/*
   int		**mat_mul(int **a, int **b, int size)
   {
   int	i;
   int	j;
   int	z;
   int	**res;

   i = 0;
   while(i < size)
   {
   j = 0;
   while (j < size)
   {
   z = 0;
   while (z < size)
   res[i][j] += a[i][z] * b[z++][j];
   j++;
   }
   i++;
   }
   return (res);
   }
   */

t_vector	mat_to_vector(int **m, t_vector src)
{
	t_vector	dst;
	float		w;

	w = src.x * m[0][3] + src.y * m[1][3] + src.z * m[2][3] + m[3][3];
	dst.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0] + m[3][0];
	dst.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] + m[3][1];
	dst.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] + m[3][2];
	if (w != 1 && w != 0) { 
		dst.x  /= w;
		dst.y /= w;
		dst.z /= w;
	}
	return (dst);
}

//relate to the cosine of the angle between two vectors
double	dot_product(t_vector i, t_vector j)
{
	double	a;
	double	b;
	double	c;

	a = i.x * j.x;
	b = i.y * j.y;
	c = i.z * j.z;
	return(a + b + c);
}

double   get_length(t_vector v)
{
	return (sqrt(dot_product(v, v)));
}

t_vector    normalize(t_vector v)
{
	float   invlen;
	float   len;

	len = get_length(v);
	if (len > 0) { 
		invlen = 1 / len; 
		v.x *= invlen;
		v.y *= invlen;
		v.z *= invlen; 
	}
	return (v);
}


/*int	main()
  {
  t_vector a;

  a.x = 1;
  a.y = 2;
  a.z = 3;
  a.length = &get_length;
  printf("len : %f", a.length(a));
  }*/
