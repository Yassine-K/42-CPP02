/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:05:20 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 16:41:45 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed () {
	val = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& fixed) {
	val = fixed.val;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		val = fixed.getRawBits();
	}
	return *this;
}

Fixed::~Fixed (){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->val;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "Destructor called" << std::endl;
	this->val = raw;
}

float Fixed::toFloat( void ) const {
	return (float) val / (1 << bits);
}

int Fixed::toInt( void ) const{
	return (int) val >> bits;
}

std::ostream & operator << (std::ostream &out,const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed (const int integer){
	std::cout << "Int constructor called" << std::endl;
	val = integer << bits;
}

Fixed::Fixed (const float floating){
	val = roundf(floating * (1 << bits));
	std::cout << "Float constructor called" << std::endl;
}