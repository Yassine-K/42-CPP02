/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:40:18 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 15:49:47 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.h"

void Point::copy_cord (float a[2], const float b[2]) {
	a[0] = b[0];
	a[1] = b[1];
}

Point::Point () {
	x = 0;
	y = 0;
	cord[0] = 0;
	cord[1] = 0;
}

Point::Point (const float a, const float b) {
	x = a;
	y = b;
	cord[0] = a;
	cord[1] = b;
}

Point::Point (const Point & point) {
	x = point.x;
	y = point.y;
	copy_cord(cord, point.cord);
}

Point & Point::operator = (const Point & point) {
	if (this != &point) {
		x = point.x;
		y = point.y;
		copy_cord(cord, point.cord);
	}
	return *this;
}

Point::~Point () {
}