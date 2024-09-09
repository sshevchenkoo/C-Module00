#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while (argc > 1 && argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            std::cout << (char)std::toupper(argv[i][j]);;
            j++;
        }
        if (i < argc - 1)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return (0);
}
