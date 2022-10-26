/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:47:35 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 19:47:37 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_object	*create_object(char type, double **t)
{
	static unsigned int	id = 0;
	t_object			*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->type = type;
	obj->id = id;
	obj->t = t;
	id++;
	return (obj);
}
