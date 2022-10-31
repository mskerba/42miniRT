/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:51:04 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/31 16:46:37 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	lighting(t_world *w,t_comp *comps, t_light *light, bool shadowed)
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

// t_tuple	lighting(t_world *w,t_comp *comps, t_light *light, bool shadowed)
// {
	// t_tuple	effective_c;
	// t_tuple	ambient;
	// t_tuple	diffuse;
	// t_tuple	specular;
	// t_tuple	lightv;
	// t_tuple	reflectv;
	// double	factor;
	// double	reflect_dot_eye;
	// double	light_dot_norm;
// 
// 
	// effective_c = create_tuple(light->intensity.x * comps->obj->m.color.x, light->intensity.y * comps->obj->m.color.y, light->intensity.z * comps->obj->m.color.z, 1);
	// effective_c = multiply_tuple(&light->intensity, &comps->obj->m.color);
	// ambient = scalar_multi(effective_c, w->ambient.ambient);
	// if (shadowed)
		// return (ambient);
	// lightv = substract_tuples(light->position, comps->over_point);
	// normalize_tuple(&lightv);
	// light_dot_norm = dot_product(lightv, comps->normalv);
	// if (light_dot_norm < 0)
		// return (ambient);
	// diffuse = scalar_multi(effective_c, w->diffuse * light_dot_norm);
	// reflectv = reflect(negate_tuple(lightv), comps->normalv);
	// normalize_tuple(&reflectv);
	// reflect_dot_eye = dot_product(reflectv, comps->eyev);
	// if (reflect_dot_eye <= 0)
		// return (add_tuples(ambient, diffuse));
	// factor = pow(reflect_dot_eye, comps->obj->m.shininess);
	// specular = scalar_multi(light->intensity, comps->obj->m.specular * factor);
	// return (add_tuples(ambient, add_tuples(diffuse, specular)));
// }
// 