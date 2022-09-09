/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:45:39 by momeaizi          #+#    #+#             */
/*   Updated: 2022/09/03 11:02:38 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H



#include <stdbool.h>
#include <math.h>

# define EPSILON 0.00001


typedef struct s_tuple
{
    double x;
    double y;
    double z;
    double w;
}   t_tuple;

#endif