#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int i = 0;
        int k = 1;
        while (k < argc)
        {
            i = 0;
            while (argv[k][i] != '\0')
            {
                if (argv[k][0] >= 'a' && argv[k][0] <= 'z')
                    argv[k][0] -= 32;
                else if ((argv[k][i] >= 'a' && argv[k][i] <= 'z') && (argv[k][i - 1] == 32 || argv[k][i - 1] == '\t' || argv[k][i - 1] == '\0'))
                    argv[k][i] -= 32;
                else if ((argv[k][i] != 32 && argv[k][i] != '\t') && (argv[k][i + 1] >= 'A' && argv[k][i + 1] <= 'Z'))
                    argv[k][i + 1] += 32;
                write(1, &argv[k][i], 1);
                i++;
            }
            k++;
            write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
}