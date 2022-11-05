/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_submatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:55:47 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:59:14 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	get_submatrix(double **m, double **sub_m, int r, int c)
{
	int		i;
	int		j;
	int		a;
	int		b;

	i = -1;
	a = 0;
	while (++i < 4)
	{
		if (i == r)
			continue ;
		j = -1;
		b = 0;
		while (++j < 4)
		{
			if (j == c)
				continue ;
			sub_m[a][b++] = m[i][j];
		}
		a++;
	}
}
