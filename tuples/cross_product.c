/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:29:03 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:30:09 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	return (
		create_tuple((a.y * b.z) - (a.z * b.y), \
		(a.z * b.x) - (a.x * b.z), \
		(a.x * b.y) - (a.y * b.x), \
		0)
	);
}