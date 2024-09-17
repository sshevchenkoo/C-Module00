#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int raw;
        static const int    fractionalBits = 8;
};

#endif
