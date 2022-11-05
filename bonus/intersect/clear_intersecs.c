/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_intersecs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:16:50 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 20:17:55 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	clear_intersecs(t_intersect **intersecs)
{
	t_intersect	*inters;
	t_intersect	*curr;

	inters = *intersecs;
	while (inters)
	{
		curr = inters;
		inters = inters->next;
		free(curr);
	}
}
