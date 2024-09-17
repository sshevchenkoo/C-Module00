#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const int rawValue);
        Fixed(const float floatValue);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);

        bool operator>(const Fixed& obj) const;
        bool operator<(const Fixed& obj) const;
        bool operator>=(const Fixed& obj) const;
        bool operator<=(const Fixed& obj) const;
        bool operator==(const Fixed& obj) const;
        bool operator!=(const Fixed& obj) const;

        Fixed operator+(const Fixed& obj) const;
        Fixed operator-(const Fixed& obj) const;
        Fixed operator*(const Fixed& obj) const;
        Fixed operator/(const Fixed& obj) const;

        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        static Fixed&  max(Fixed &a, Fixed &b);
        static Fixed&  min(Fixed &a, Fixed &b);
        static const Fixed&  max(const Fixed &a, const Fixed &b);
        static const Fixed&  min(const Fixed &a, const Fixed &b);
    private:
        int raw;
        static const int    fractionalBits = 8;
};

#endif
