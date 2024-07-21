/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:39:08 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 17:14:24 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.h"


float area (const float a[2], const float b[2],const float c[2]) {
	float res;
	res = (a[0] * (b[1] - c[1])) + (b[0] * (c[1] - a[1])) + (c[0] * (a[1] - b[1]));
	if (res < 0)
		res *= -1;
	return res;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float abc, apc, apb, pbc;
	abc = area(a.cord, b.cord, c.cord);
	apc = area(a.cord, point.cord, c.cord);
	apb = area(a.cord, point.cord, b.cord);
	pbc = area(point.cord, b.cord, c.cord);
	if (abc != apb + apc + pbc)
		return false;
	return true;
}
