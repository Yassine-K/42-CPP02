/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:54:16 by ykhayri           #+#    #+#             */
/*   Updated: 2024/01/15 10:23:19 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	private:
		static const int	fr;
		int					num;
	public:
		Fixed ( void );
		~Fixed ( void );
		Fixed (const Fixed &f);
		Fixed & operator = (const Fixed &f);
		int getRawBits( void ) const;
		void setRawBits( int const raw );	
};