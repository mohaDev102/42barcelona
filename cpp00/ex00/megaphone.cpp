
#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    
    int j = 0;
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (0);
    }
    for (int i = 1; i < argc; ++i)
    {
        j = 0;
        while (i <= argv[i][j])
        {
            std::cout << (char)std::toupper(argv[i][j]);
            j++;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
