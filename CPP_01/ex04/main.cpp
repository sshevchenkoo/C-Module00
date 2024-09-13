# include <iostream>
# include <string>
# include <iomanip>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Ente <file name> <string 1> <string 2>" << std::endl;
        return (1);
    }

    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string line;
    std::string infile = argv[1];
    std::string outfilename = infile + ".replace";
    std::ifstream   file(infile);
    std::ofstream   outfile(outfilename);

    if (!file.is_open())
    {
        std::cerr << "Error : open file" << std::endl;
        return (1);
    }
    if (!outfile.is_open())
    {
        std::cerr << "Error : create file" << std::endl;
        return (1);
    }

    while (std::getline(file, line))
    {
        size_t  found;
        size_t  pos = 0;
        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(found, s1.size(), s2);
            pos = found + s2.size();
        }
        outfile << line + '\n';
    }

    file.close();
    outfile.close();
    return (0);
}
