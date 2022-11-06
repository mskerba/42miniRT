/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:55:39 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

double	determinant(double **m, double **cofactors)
{
	double	det;
	int		i;

	det = 0;
	i = -1;
	while (++i < 4)
		det += m[0][i] * cofactors[0][i];
	return (det);
}
