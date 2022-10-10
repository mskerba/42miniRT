/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:25:54 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/10 20:51:25 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"



double  **translation(double x, double y, double z)
{
    double  **matrix;
    int     i;
    int     j;

    matrix = create_matrix(4, 4);
    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            if (j == i)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    matrix[0][3] = x;
    matrix[1][3] = y;
    matrix[2][3] = z;
    return (matrix);
}

double  **rotation_x(double r)
{
    double  **matrix;

    matrix = create_matrix(4, 4);
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    
    matrix[1][0] = 0;
    matrix[1][1] = cos(r);
    matrix[1][2] = -sin(r);
    matrix[1][3] = 0;
    
    matrix[2][0] = 0;
    matrix[2][1] = sin(r);
    matrix[2][2] = cos(r);
    matrix[2][3] = 0;
    
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
    return (matrix);
}

double  **rotation_y(double r)
{
    double  **matrix;

    matrix = create_matrix(4, 4);
    matrix[0][0] = cos(r);
    matrix[0][1] = 0;
    matrix[0][2] = sin(r);
    matrix[0][3] = 0;
    
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    
    matrix[2][0] = -sin(r);
    matrix[2][1] = 0;
    matrix[2][2] = cos(r);
    matrix[2][3] = 0;
    
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
    return (matrix);
}

double  **rotation_z(double r)
{
    double  **matrix;

    matrix = create_matrix(4, 4);
    matrix[0][0] = cos(r);
    matrix[0][1] = -sin(r);
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    
    matrix[1][0] = sin(r);
    matrix[1][1] = cos(r);
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
    matrix[2][3] = 0;
    
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
    return (matrix);
}

double  **scaling(double x, double y, double z)
{
    double  **matrix;
    int     i;
    int     j;

    matrix = create_matrix(4, 4);
    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            matrix[i][j] = 0;
    }
    matrix[0][0] = x;
    matrix[1][1] = y;
    matrix[2][2] = z;
    matrix[3][3] = 1;
    return (matrix);
}

double  **shearing(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y)
{
    double  **matrix;

    matrix = create_matrix(4, 4);
    matrix[0][0] = 1;
    matrix[0][1] = x_y;
    matrix[0][2] = x_z;
    matrix[0][3] = 0;
    matrix[1][0] = y_x;
    matrix[1][1] = 1;
    matrix[1][2] = y_z;
    matrix[1][3] = 0;
    matrix[2][0] = z_x;
    matrix[2][1] = z_y;
    matrix[2][2] = 1;
    matrix[2][3] = 0;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
    return (matrix);
}