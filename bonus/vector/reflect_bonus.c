/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:30:12 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_tuple	reflect(t_tuple lightv, t_tuple normal)
{
	t_tuple	reflect;
	double	dot;

	dot = 2 * dot_product(lightv, normal);
	reflect = scalar_multi(normal, dot);
	reflect = substract_tuples(lightv, reflect);
	return (reflect);
}
