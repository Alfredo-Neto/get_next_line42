int    get_next_line(int fd, char **line)
{
    static char    	*save;
    ssize_t        	size_read;
    char        	*buffer;
    char        	*temp;

    buffer = malloc(BUFFER_SIZE + 1);
    size_read = read(fd, buffer, BUFFER_SIZE);
    while (size_read > 0)
    {
        buffer[size_read] = '\0';
        if (save == NULL)
            save = ft_strdup(buffer);
        else
        {
            temp = ft_strjoin(save, buffer);
            free(save);
            save = temp;
        }
        if (ft_strchr(save, '\n'))
            break ;
        size_read = read(fd, buffer, BUFFER_SIZE);
    }
    free(buffer);
    return (output(&save, line, size_read));
}