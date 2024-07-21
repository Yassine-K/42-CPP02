/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:05:20 by ykhayri           #+#    #+#             */
/*   Updated: 2024/07/21 16:43:33 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed () {
	val = 0;
}

Fixed::Fixed (const Fixed& fixed) {
	val = fixed.val;
}

Fixed::Fixed (const int integer){
	val = integer << bits;
}

Fixed::Fixed (const float floating){
	val = roundf(floating * (1 << bits));
}

Fixed::~Fixed (){
}

int Fixed::getRawBits( void ) const {
	return this->val;
}

void Fixed::setRawBits( int const raw ) {
	this->val = raw;
}

float Fixed::toFloat( void ) const {
	return (float) val / (1 << bits);
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
	float tmp = (float) (val * fixed.val) / (1 << bits * 2);
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