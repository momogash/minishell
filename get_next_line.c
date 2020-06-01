#include "get_next_line.h"

// int				ft_newline(char **str, char **line, int fd, int reader)
// {
// 	char			*tmp;
// 	unsigned int	i;
// 	unsigned int	len;

// 	i = 0;
// 	while (str[fd][i] != '\n' && str[fd][i] != '\0')
// 		i++;
// 	if (str[fd][i] == '\n')
// 	{
// 		len = i;
// 		*line = ft_strsub(str[fd], 0, len);
// 		tmp = ft_strdup(str[fd] + len + 1);
// 		free(str[fd]);
// 		str[fd] = tmp;
// 		if (str[fd][0] == '\0')
// 			// ft_strdel(&str[fd]);
// 			free(&str[fd]);
// 	}
// 	else if (str[fd][i] == '\0')
// 	{
// 		if (reader == BUFF_SIZE)
// 			return (get_next_line(fd, line));
// 		*line = ft_strdup(str[fd]);
// 		// ft_strdel(&str[fd]);
// 		free(&str[fd]);
// 		free(str[fd]);
// 	}
// 	return (1);
// }

// int				get_next_line(const int fd, char **line)
// {
// 	static char	*multi_fd[1024];
// 	char		buff[BUFF_SIZE + 1];
// 	char		*tmp;
// 	int			rd_bytes;

// 	if (fd < 0 || !line)
// 		return (-1);
// 	while ((rd_bytes = read(fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		buff[rd_bytes] = '\0';
// 		if (multi_fd[fd] == NULL)
// 			multi_fd[fd] = ft_strnew(1);
// 		tmp = ft_strjoin(multi_fd[fd], buff);
// 		free(multi_fd[fd]);
// 		multi_fd[fd] = tmp;
// 		if (ft_strchr(multi_fd[fd], '\n'))
// 			break ;
// 	}
// 	if (rd_bytes < 0)
// 		return (-1);
// 	else if (rd_bytes == 0 && (multi_fd[fd] == NULL || multi_fd[fd][0] == '\0'))
// 		return (0);
// 	return (ft_newline(multi_fd, line, fd, rd_bytes));
// }
# define BUFF_SIZE 32
# define FD_MAX 1024

static int	line_copy(char *buf, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (((int)ft_strlen(line)) > i + 1)
		buf = ft_strcpy(buf, &(line[i + 1]));
	line[i] = '\0';
	return (1);
}

static int	get_line(const int fd, char **buf, char **line)
{
	int		r;
	char	*store;

	r = 1;
	if (buf[fd][0] != '\0')
		*line = ft_strcpy(*line, buf[fd]);
	ft_bzero(buf[fd], BUFF_SIZE);
	while (!(ft_strchr(*line, '\n')) && (r = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		store = *line;
		*line = ft_strjoin(store, buf[fd]);
		free(store);
		if (!*line)
			return (-1);
		ft_bzero(buf[fd], BUFF_SIZE);
	}
	if (r >= 0 && *line[0] != '\0')
		return (line_copy(buf[fd], *line));
	return (r);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[FD_MAX];

	if (fd < 0 || fd > FD_MAX || read(fd, buf[fd], 0) < 0 || !line)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(BUFF_SIZE + 1);
	return (get_line(fd, buf, line));
}