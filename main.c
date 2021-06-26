#include "get_next_line.h"

int main(void)
{
        char *linha;
        int fd;

        fd = open("/home/alfredobraule/gnl_test.txt", O_RDONLY);
        // printf("%d", get_next_line(fd, &linha));
        while (get_next_line(fd, &linha))
        {
                // *line = NULL;
                printf("%s", linha);
                printf("\n");
                free(linha);
        }
        free(linha);
}
// #include <stdio.h>
// #include <fcntl.h>
// #include <stddef.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include "get_next_line.h"

// void    doprint(int out, char **str, int line)
// {
//     printf("(LINE %i) [OUT %i] |%s|\n", line, out, *str);
//     free(*str);
//     *str = NULL;
// }

// int main()
// {
//     int fd;

//     char    *st;
//     int        out;
//     int        i;

//     st = NULL;
//     i = 0;
//     out = 1;
//     fd = open("/home/alfredobraule/gnl_test.txt", O_RDWR);
//     while (out)
//     {
//         out = get_next_line(-1, NULL);
//         doprint(out, &st, i++);
//         if (out < 0)
//             break;
//     }
//     close(fd);
    
//     return (0);
// }