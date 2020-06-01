// #ifndef __GET_NEXT_LINE_H
// # define __GET_NEXT_LINE_H
// # include <fcntl.h>
// # include <sys/stat.h>
// # include <sys/types.h>
// # include "libft/libft.h"
// # define BUFF_SIZE 1
// # define EXIT -1
// # define OK 1

// int		get_next_line(const int fd, char **line);

// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define LINE_BUFF 100
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define FD_MAX 1024
# define IS_BUFF_EMPTY file.buff[0] == '\0'

typedef struct		s_buff
{
	char			*buff;
	char			*start;
	char			*tmp;
}					t_buff;

int					get_next_line(const int fd, char **line);
#endif