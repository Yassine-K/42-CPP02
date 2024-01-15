/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:22:16 by ykhayri           #+#    #+#             */
/*   Updated: 2024/01/15 10:24:08 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fr = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	num = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &f) {
	std::cout << "Copy constructor called"  << std::endl;
	this->num = f.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = f.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return num;
}

void Fixed::setRawBits( int const raw ) {
	num = raw;
}