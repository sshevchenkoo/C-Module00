#include "phonebook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0)
{

} 

void    PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << "Write First Name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);
    std::cout << "Write Last Name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);
    std::cout << "Write nickname: ";
    std::getline(std::cin, input);
    newContact.setNickName(input);
    std::cout << "Write phone number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);
    std::cout << "Write darkest secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);
    contacts[currentIndex] = newContact;
    currentIndex = (currentIndex + 1)%8;
    if (contactCount < 8)
        contactCount++;
}

void    PhoneBook::displayContact(int index) const
{
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void    PhoneBook::dispalyContacts() const
{
    int i;

    i = 0;
    std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << std::endl;
    while (i < contactCount)
    {
        std::string firstname = contacts[i].getFirstName();
        std::string lastname = contacts[i].getLastName();
        std::string nickname = contacts[i].getNickName();
        if (firstname.length() > 10)
            firstname = firstname.substr(0, 9) + ".";
        if (lastname.length() > 10)
            lastname = lastname.substr(0, 9) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";
        std::cout << std::setw(10) << i + 1 << "|"
                    << std::setw(10) << firstname << "|"
                    << std::setw(10) << lastname << "|"
                    << std::setw(10) << nickname << std::endl;
        i++;
    }
}
void    PhoneBook::searchContact() const
{
    int i;
    std::string input;

    if (contactCount == 0)
        return ;
    dispalyContacts();
    std::cout << "Write index of the contact: ";
    std::getline(std::cin, input);
    i = std::stoi(input);
    if (i >= 1 && i <= contactCount)
        displayContact(i - 1);
    else
        std::cout << "Invalid index" << std::endl;
}
