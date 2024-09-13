# include <iostream>
# include <string>
# include <iomanip>

int main()
{
    std::string s;
    std::string *stringPTR;
    std::string &stringREF = s;

    s = "HI THIS IS BRAIN";
    stringPTR = &s;

    std::cout << "Address of string variable: " << &s << std::endl;
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address held by stringREF: " << &stringREF << std::endl;

    std::cout << "Value of string variable: " << s << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}
