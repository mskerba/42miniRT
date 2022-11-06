/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:29:03 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	return (
		create_tuple((a.y * b.z) - (a.z * b.y), \
		(a.z * b.x) - (a.x * b.z), \
		(a.x * b.y) - (a.y * b.x), \
		0)
	);
}
