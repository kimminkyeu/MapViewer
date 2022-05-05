/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:36:38 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/04 16:59:53 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/matrix.h"

t_mat4x4	parallel(void)
{
	static t_mat4x4	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4	isometric(void)
{
	static t_mat4x4	mat;

	mat = multiply_matrix4x4(rotate_y_3d(30.0f), rotate_x_3d(30.0f));
	mat = multiply_matrix4x4(rotate_z_3d(30.0f), mat);
	return (mat);
}

t_mat4x4	perspective(void)
{
	static t_mat4x4	mat;
	float			f_far;
	float			f_near;
	float			f_field_of_view;
	float			f_fov_cotan;

	f_far = 100.0f;
	f_near = 0.1f;
	f_field_of_view = 45.0f;
	f_fov_cotan = 1.0f / tanf(get_radian(f_field_of_view / 2.0f));
	mat.m[0][0] = f_fov_cotan;
	mat.m[1][1] = f_fov_cotan;
	mat.m[2][2] = (f_far + f_near) / (f_far - f_near);
	mat.m[2][3] = 2 * f_far * f_near / (f_far - f_near);
	mat.m[3][2] = -1.0f;
	mat.m[3][3] = 0.0f;
	return (mat);
}
