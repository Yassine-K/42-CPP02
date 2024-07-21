/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:32:43 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 10:52:40 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
	public:
		Fixed ();
		Fixed (const Fixed&);
		Fixed & operator = (const Fixed&);
		~Fixed ();
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					val;
		static const int	bits;
};