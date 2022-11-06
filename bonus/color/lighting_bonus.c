/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:51:04 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_tuple	lighting(t_world *w, t_comp *comps, t_light *light, bool shadowed)
{
	t_phong	phong;

	phong.effective_c = multiply_tuple(&light->intensity, &comps->obj->m.color);
	phong.ambient = scalar_multi(phong.effective_c, w->ambient.ambient);
	if (shadowed)
		return (phong.ambient);
	phong.lightv = substract_tuples(light->position, comps->over_point);
	normalize_tuple(&phong.lightv);
	phong.light_dot_norm = dot_product(phong.lightv, comps->normalv);
	if (phong.light_dot_norm < 0)
		return (phong.ambient);
	phong.diffuse = scalar_multi(phong.effective_c, \
	w->diffuse * phong.light_dot_norm);
	phong.reflectv = reflect(negate_tuple(phong.lightv), comps->normalv);
	normalize_tuple(&phong.reflectv);
	phong.reflect_dot_eye = dot_product(phong.reflectv, comps->eyev);
	if (phong.reflect_dot_eye <= 0)
		return (add_tuples(phong.ambient, phong.diffuse));
	phong.factor = pow(phong.reflect_dot_eye, comps->obj->m.shininess);
	phong.specular = scalar_multi(light->intensity, \
	comps->obj->m.specular * phong.factor);
	return (
		add_tuples(phong.ambient, add_tuples(phong.diffuse, phong.specular))
	);
}
