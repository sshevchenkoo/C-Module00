#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact 
{
    public:
        void    setFirstName(const std::string &firstname);
        void    setLastName(const std::string &lastname);
        void    setNickName(const std::string &nickname);
        void    setPhoneNumber(const std::string &phonenumber);
        void    setDarkestSecret(const std::string &darkestsecret);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;

    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

class PhoneBook
{
    public:
        PhoneBook();
        void    addContact();
        void    searchContact() const;

    private:
        Contact contacts[8];
        int currentIndex;
        int contactCount;
        void    displayContact(int index) const;
        void    dispalyContacts() const;
};

#endif
