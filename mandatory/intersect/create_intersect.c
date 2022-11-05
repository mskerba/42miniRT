/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:07:25 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 20:07:47 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_intersect	*create_intersect(double t, t_object *obj)
{
	t_intersect	*inter_section;

	inter_section = (t_intersect *)malloc(sizeof(t_intersect));
	inter_section->object = obj;
	inter_section->t = t;
	inter_section->next = NULL;
	return (inter_section);
}
