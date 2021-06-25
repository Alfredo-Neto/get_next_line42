#include "get_next_line.h"

int main(void)
{
        char *linha;
        int fd;

        fd = open("/home/alfredobraule/gnl_test.txt", O_RDONLY);
        while (get_next_line(fd, &linha))
        {
                // *line = NULL;
                printf("%s", linha);
                printf("\n");
                free(linha);
        }
        free(linha);
}