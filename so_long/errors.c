
#include "so_long.h"

void error_param(char *msg, char **map)
{
    //printf("error param\n");
    if (map)
        free(map);
    if (ft_strlen(msg) != 0)
        write(1, msg, ft_strlen(msg));
    exit(1);
}