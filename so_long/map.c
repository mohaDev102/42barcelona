
#include "so_long.h"

t_err ft_newmap_error()
{
    t_err map_err;

    map_err.rowlen = 0;
    map_err.nplayer = 0;
    map_err.ncollect = 0;
    map_err.nexits = 0;
    map_err.nwalls = 0;
    return (map_err);
}

void ft_read_map(int fd, t_err *map_err, t_flood *g, char **map_str)
{
    char *line;
    char *last_line;

    line = NULL;
    last_line = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            if (!g->ncol)
                error_param("Map is empty", NULL);
            else
                ft_checkmap(last_line, map_err, g, 1);
            free(last_line);
            break ;
        }
        free(last_line);
        ft_checkmap(line, map_err, g, !g->nrow);
        last_line = ft_substr(line, 0, ft_strlen(line));
        *map_str = ft_strlenline(*map_str, line);
        g->nrow++;
    }
}

void ft_checkmap(char *line, t_err *map_err, t_flood *g, int last)
{
    if (!g->ncol)
        g->ncol = ft_strlen(line) - 1;
    if (g->ncol && ((g->ncol-> != ft_strlen(line) - 1 && ft_strchr(line, '\n')) || (g->ncol != ft_strlen(line) && !ft_strchr(line, '\n'))))
    {
        map_err->rowlen = 1;
    }
    
}