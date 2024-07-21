/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:32:43 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 15:20:58 by ykhayri          ###   ########.fr       */
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
		static Fixed& min (Fixed& a, Fixed& b);
		static const Fixed& min (const Fixed& a, const Fixed& b);
		static Fixed& max (Fixed& a, Fixed& b);
		static const Fixed& max (const Fixed& a, const Fixed& b);
		bool operator > (const Fixed& fixed);
		bool operator < (const Fixed& fixed);
		bool operator >= (const Fixed& fixed);
		bool operator <= (const Fixed& fixed);
		bool operator == (const Fixed& fixed);
		bool operator != (const Fixed& fixed);
		Fixed operator + (const Fixed& fixed);
		Fixed operator - (const Fixed& fixed);
		Fixed operator * (const Fixed& fixed);
		Fixed operator / (const Fixed& fixed);
		Fixed& operator++ ();
		Fixed operator++ (int);
		Fixed& operator-- ();
		Fixed operator-- (int);

	private:
		int					val;
		static const int	bits;
};

std::ostream & operator << (std::ostream &out,const Fixed& fixed);