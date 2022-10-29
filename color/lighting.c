/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:51:04 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/29 11:40:57 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	lighting(t_comp *comps, t_light *light, bool shadowed)
{
	t_tuple	effective_c;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	factor;
	double	reflect_dot_eye;
	double	light_dot_norm;

	effective_c = multiply_tuple(&light->intensity, &comps->obj->m.color);
	ambient = scalar_multi(effective_c, comps->obj->m.ambient);
	if (shadowed)
		return (ambient);
	lightv = substract_tuples(light->position, comps->over_point);
	normalize_tuple(&lightv);
	light_dot_norm = dot_product(lightv, comps->normalv);
	if (light_dot_norm < 0)
		return (ambient);
	diffuse = scalar_multi(effective_c, comps->obj->m.diffuse * light_dot_norm);
	reflectv = reflect(negate_tuple(lightv), comps->normalv);
	normalize_tuple(&reflectv);
	reflect_dot_eye = dot_product(reflectv, comps->eyev);
	if (reflect_dot_eye <= 0)
		return (add_tuples(ambient, diffuse));
	factor = pow(reflect_dot_eye, comps->obj->m.shininess);
	specular = scalar_multi(light->intensity, comps->obj->m.specular * factor);
	return (add_tuples(ambient, add_tuples(diffuse, specular)));
}
