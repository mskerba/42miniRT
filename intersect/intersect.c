/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:06:06 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/05 09:30:26 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	*intersect(t_ray r, double radius, double *t)
{
	t_tuple	s_to_r;
	double	a;
	double	b;
	double	c;
	double	descriminant;

	s_to_r = create_tuple(r.origin.x, r.origin.y, r.origin.z, 0);
	a = dot_product(r.direction, r.direction);
	b = 2 * dot_product(r.direction, s_to_r);
	c = dot_product(s_to_r, s_to_r) - radius;
	descriminant = pow(b, 2) - (4 * a * c);
	if (descriminant < 0)
		return (NULL);
	t = malloc(2 * sizeof(double));
	t[0] = (-b - sqrt(descriminant)) / (2 * a);
	t[1] = (-b + sqrt(descriminant)) / (2 * a);
	if (t[1] < t[0])
		t[0] = t[1];
	return (t);
}
