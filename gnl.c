#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <unistd.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *join;
    size_t    len;
    size_t    i;
    size_t    j;

    len = (strlen(s1) + strlen(s2)) + 1;
    join = (char *)malloc(len);
    if (!s1 || !s2 || join == 0)
        return (0);
    i = 0;
    while (s1[i] != '\0')
    {
        join[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
        join[i++] = s2[j++];
    join[i] = '\0';
    return (join);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t    i;
    size_t    substr_len;
    char    *substr;

    i = 0;
    if (s == 0)
        return (0);
    substr_len = strlen(s);
    if (substr_len < len)
        substr = (char *)malloc((substr_len + 1) * sizeof(char));
    else
        substr = (char *)malloc((len + 1) * sizeof(char));
    if (substr == 0)
        return (0);
    while (i < len && (start + i) < substr_len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}
static int    gnl_end_line(char *s_line)
{
    int i;

    i = 0;
    if (s_line == 0)
        return (-1);
    while (s_line[i] != '\0')
    {
        if (s_line[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

static int    gnl_return_line(char **s_line, char **line)
{
    int        i;
    char    *tmp;

    i = gnl_end_line(*s_line);
    if (i >= 0)
    {
        *line = ft_substr(*s_line, 0, i);
        tmp = ft_substr(*s_line, i + 1, strlen(*s_line));
        free(*s_line);
        *s_line = tmp;
        tmp = NULL;
        return (1);
    }
    else
        return (0);
}

int            get_next_line(int fd, char **line)
{
    char        buff[5000];
    ssize_t        ret;
    static char    *s_l[5000];

    if (line == 0 || fd < 0 || BUFFER_SIZE <= 0)
        return (-1);
    if (s_l[fd] != NULL)
    {
        if (gnl_return_line(&s_l[fd], line) == 1)
            return (1);
    }
    else
        s_l[fd] = strdup("");
    ret = read(fd, buff, BUFFER_SIZE);
    while (ret > 0)
    {
        buff[ret] = '\0';
        s_l[fd] = s_l[fd] == NULL ? strdup(buff) : ft_strjoin(s_l[fd], buff);
        if (s_l[fd] == 0)
            return (-1);
        if (gnl_return_line(&s_l[fd], line) == 1)
            return (1);
        ret = read(fd, buff, BUFFER_SIZE);
    }
    *line = ret < 0 ? NULL : s_l[fd];
    s_l[fd] = NULL;
    return (ret);
}

int main()
{
    char *linha;
    int fd;
    
    fd = open("/home/alfredobraule/gnl_test.txt", O_RDONLY);
   while (get_next_line(fd, &linha))
   {
        printf("%s", linha);
        printf("\n");
        free(linha);
   }
    // printf("%s", linha);
    // printf("\n");
    
}