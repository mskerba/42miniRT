/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:27:38 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:30:30 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	magnitude(t_tuple tuple)
{
	return (sqrt(pow(tuple.x, 2) \
	+ pow(tuple.y, 2) \
	+ pow(tuple.z, 2) \
	+ pow(tuple.w, 2)));
}
