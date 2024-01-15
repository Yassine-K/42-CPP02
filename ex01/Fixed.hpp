/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:32:04 by ykhayri           #+#    #+#             */
/*   Updated: 2024/01/15 12:14:49 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	private:
		static const int	fractional;
		int					num;
		int					fl;
	public:
		Fixed ( void );
		Fixed ( const int n );
		Fixed ( const float n );
		~Fixed ( void );
		Fixed (const Fixed &f);
		Fixed & operator = (const Fixed &f);
		friend std::ostream& operator << (std::ostream& os, const Fixed &f);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};