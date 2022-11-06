/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_intersect_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:07:25 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_intersect	*create_intersect(double t, t_object *obj)
{
	t_intersect	*inter_section;

	inter_section = (t_intersect *)malloc(sizeof(t_intersect));
	inter_section->object = obj;
	inter_section->t = t;
	inter_section->next = NULL;
	return (inter_section);
}
