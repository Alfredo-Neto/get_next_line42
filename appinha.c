int				get_next_line(int fd, char **line)
{
	static char	*buff[OPEN_MAX];
	char		tmp[ARG_MAX];
	int			ret[2];

	if (fd >= 0 && line && BUFFER_SIZE > 0 && (*line = ft_strdup("")))
	{
		ret[0] = NO_ENDLINE;
		while (ret[0] == NO_ENDLINE)
		{
			if (buff[fd] == NULL && (ret[1] = read(fd, tmp, BUFFER_SIZE)) >= 0
				&& (tmp[ret[1]] = '\0') == 0)
				buff[fd] = ft_strdup(tmp);
			if (buff[fd] != NULL)
				ret[1] = ft_strlen(buff[fd]);
			if (ret[1] < 0)
				break ;
			ret[0] = ft_buff2line(&*line, &buff[fd]);
			if (ret[1] == 0)
				return (EOF_RCHD);
		}
		if (ret[0] == FOUND_ENDLINE)
			return (READL_OK);
	}
	ft_free_null(&*line);
	return (ERR_HPND);
}