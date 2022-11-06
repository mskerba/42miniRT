/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:48:03 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

void	add_object(t_object **obj, char type, double **t)
{
	static unsigned int	id = 0;
	t_object			*new_obj;

	new_obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return ;
	new_obj->type = type;
	new_obj->id = id;
	new_obj->t = t;
	new_obj->next = *obj;
	*obj = new_obj;
	id++;
}
