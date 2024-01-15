/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:32:00 by ykhayri           #+#    #+#             */
/*   Updated: 2024/01/15 12:15:09 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	num = 0;
	fl = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &f) {
	std::cout << "Copy constructor called"  << std::endl;
	this->num = f.getRawBits();
}

Fixed::Fixed (const int n) {
	std::cout << "Int constructor called"  << std::endl;
	num = n;
}

Fixed::Fixed (const float n) {
	std::cout << "Float constructor called"  << std::endl;
	num = n;
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = f.getRawBits();
	return *this;
}


std::ostream& operator<<(std::ostream& os, const Fixed &f) {
	os << f.num << "." << f.fl;
	return os;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return num;
}

void Fixed::setRawBits( int const raw ) {
	num = raw;
}


float	Fixed::toFloat( void ) const {
	return (float) num;
}

int		Fixed::toInt( void ) const {
	return (int) num;
}