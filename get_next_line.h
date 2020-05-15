#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"
# define BUFF_SIZE 1
# define EXIT -1
# define OK 1

int		get_next_line(const int fd, char **line);

#endif