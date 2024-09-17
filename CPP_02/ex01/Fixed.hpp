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
    private:
        int raw;
        static const int    fractionalBits = 8;
};

#endif
