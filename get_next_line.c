#include "get_next_line.h"

static char	*get_res(char *temp, char **line)
{
	int		ind;
	int		j;
	char	*hold;

	j = ft_strlen(temp);
	if (ft_strchr(temp, '\n'))
	{
		ind = ft_strchr(temp, '\n') - temp;
		*line = ft_strsub(temp, 0, ind);
		hold = temp;
		temp = ft_strsub(temp, ind + 1, j - (ind + 1));
		free(hold);
		return (temp);
	}
	else
		*line = temp;
	temp = NULL;
	return (temp);
}

static int	get_line(const int fd, char buff[BUFF_SIZE + 1], char **line)
{
	static char	*temp = NULL;
	char		*hold;
	int			j;

	if (!temp)
		temp = ft_strnew(1);
	while ((j = read(fd, buff, BUFF_SIZE)) > 0)
	{
		hold = temp;
		buff[j] = '\0';
		temp = ft_strjoin(temp, buff);
		free(hold);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if ((j = ft_strlen(temp)) == 0)
		return (0);
	else
	{
		temp = get_res(temp, line);
		return (OK);
	}
}

int			get_next_line(const int fd, char **line)
{
	int		res;
	char	buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, buff, 0) < 0)
		return (EXIT);
	res = get_line(fd, buff, line);
	if (res < 0)
		return (EXIT);
	else if (res == 0)
		return (0);
	else
		return (OK);
}
