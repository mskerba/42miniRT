/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:39:51 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:40:11 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**translation(double x, double y, double z)
{
	double	**matrix;

	matrix = scaling(1, 1, 1);
	matrix[0][3] = x;
	matrix[1][3] = y;
	matrix[2][3] = z;
	return (matrix);
}
