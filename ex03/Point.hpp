/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:40:24 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 15:49:34 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Fixed.hpp"

class Point {
	public:
		float cord[2];
		Point ();
		Point (const float, const float);
		Point (const Point &);
		Point & operator = (const Point &);
		~Point ();
		void copy_cord(float a[2], const float b[2]);

	private:
		Fixed x;
		Fixed y;
};