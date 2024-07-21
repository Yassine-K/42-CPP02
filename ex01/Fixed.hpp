/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:32:43 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 12:26:03 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed ();
		Fixed (const int);
		Fixed (const float);
		Fixed (const Fixed&);
		Fixed & operator = (const Fixed&);
		~Fixed ();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int					val;
		static const int	bits;
};

std::ostream & operator << (std::ostream &out,const Fixed& fixed);