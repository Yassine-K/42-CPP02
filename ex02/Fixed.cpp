/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:05:20 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 14:32:05 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::bits = 8;

Fixed::Fixed () {
	val = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& fixed) {
	val = fixed.val;
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed (const int integer){
	// std::cout << "Int constructor called" << std::endl;
	val = integer << bits;
}

Fixed::Fixed (const float floating){
	val = roundf(floating * std::pow(2, bits));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed (){
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->val;
}

void Fixed::setRawBits( int const raw ) {
	// std::cout << "Destructor called" << std::endl;
	this->val = raw;
}

float Fixed::toFloat( void ) const {
	return val / std::pow(2, bits);
}

int Fixed::toInt( void ) const{
	return (int) val >> bits;
}
Fixed& Fixed::min (Fixed& a, Fixed& b){
	if (a.val > b.val)
		return b;
	return a;
}

const Fixed& Fixed::min (const Fixed& a, const Fixed& b){
	if (a.val > b.val)
		return b;
	return a;
}

Fixed& Fixed::max (Fixed& a, Fixed& b){
	if (a.val < b.val)
		return b;
	return a;
}

const Fixed& Fixed::max (const Fixed& a, const Fixed& b){
	if (a.val < b.val)
		return b;
	return a;
}

Fixed& Fixed::operator = (const Fixed& fixed) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		val = fixed.getRawBits();
	}
	return *this;
}

bool Fixed::operator > (const Fixed& fixed) {
	return val > fixed.val;
}

bool Fixed::operator < (const Fixed& fixed) {
	return val < fixed.val;
}

bool Fixed::operator >= (const Fixed& fixed) {
	return val >= fixed.val;
}

bool Fixed::operator <= (const Fixed& fixed) {
	return val <= fixed.val;
}

bool Fixed::operator == (const Fixed& fixed) {
	return val == fixed.val;
}

bool Fixed::operator != (const Fixed& fixed) {
	return val != fixed.val;
}

Fixed Fixed::operator + (const Fixed& fixed) {
	return Fixed(val + fixed.val);
}

Fixed Fixed::operator - (const Fixed& fixed) {
	return Fixed(val - fixed.val);
}

Fixed Fixed::operator * (const Fixed& fixed) {
	float tmp = (val * fixed.val) / std::pow(2, bits * 2);
	return Fixed(tmp);
}

Fixed Fixed::operator / (const Fixed& fixed) {
	return Fixed(val / fixed.val);
}

Fixed& Fixed::operator++ () {
	val++;
	return *this;
}

Fixed Fixed::operator++ (int) {
	Fixed tmp(*this);
	val++;
	return tmp;
}

Fixed& Fixed::operator-- () {
	val--;
	return *this;
}

Fixed Fixed::operator-- (int) {
	Fixed tmp(*this);
	val--;
	return tmp;
}

std::ostream & operator << (std::ostream &out,const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}