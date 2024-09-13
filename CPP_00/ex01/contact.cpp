#include "phonebook.hpp"

void    Contact::setFirstName(const std::string &firstname)
{
    this->firstName = firstname;
}

void    Contact::setLastName(const std::string &lastname)
{
    this->lastName = lastname;
}

void    Contact::setNickName(const std::string &nickname)
{
    this->nickName = nickname;
}

void    Contact::setPhoneNumber(const std::string &phonenumber)
{
    this->phoneNumber = phonenumber;
}

void    Contact::setDarkestSecret(const std::string &darkestsecret)
{
    this->darkestSecret = darkestsecret;
}

std::string Contact::getFirstName() const
{
    return (this->firstName);
}

std::string Contact::getLastName() const
{
    return (this->lastName);
}

std::string Contact::getNickName() const
{
    return (this->nickName);
}

std::string Contact::getPhoneNumber() const
{
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (this->darkestSecret);
}
