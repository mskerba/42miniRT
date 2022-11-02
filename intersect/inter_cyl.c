/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:54:03 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/02 21:16:38 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	*inter_cyl(t_ray r)
{
	double	a;
	double	b;
	double	c;
	double	descriminant;
	double	*inter;

	a = pow(r.direction.x, 2) + pow(r.direction.z, 2);
	if (a <= EPSILON && a >= -EPSILON)
		return (0);
	b = 2 * r.direction.x * r.origin.x + 2 * r.direction.z * r.origin.z;
	c = pow(r.origin.x, 2) + pow(r.origin.z, 2) - 1;
	descriminant = pow(b, 2) - (4 * a * c);
	if (descriminant < EPSILON)
		return (NULL);
	inter = malloc(2 * sizeof(double));
	inter[0] = (-b - sqrt(descriminant)) / (2 * a);
	inter[1] = (-b + sqrt(descriminant)) / (2 * a);
	if (inter[1] < inter[0])
		inter[0] = inter[1];
	return (inter);
}
