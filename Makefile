CFLAGS = -Wall -Werror -Wextra -g

NAME = minishell
LIB = libftminishell

OBJ = libft/ft_bzero.o libft/ft_isdigit.o libft/ft_strlen.o libft/ft_tolower.o libft/ft_memchr.o libft/ft_memset.o libft/ft_strstr.o libft/ft_toupper.o libft/ft_strclr.o libft/ft_strnew.o libft/ft_putchar.o libft/ft_putstr.o libft/ft_isalpha.o libft/ft_isprint.o libft/ft_isalnum.o libft/ft_isascii.o libft/ft_strdup.o libft/ft_strcpy.o libft/ft_putendl.o libft/ft_putstr_fd.o libft/ft_putchar_fd.o libft/ft_strequ.o libft/ft_strjoin.o libft/ft_strchr.o libft/ft_strrchr.o libft/ft_memcmp.o libft/ft_strcmp.o libft/ft_strncmp.o libft/ft_strncpy.o libft/ft_memalloc.o libft/ft_putnbr.o libft/ft_putnbr_fd.o libft/ft_strnequ.o libft/ft_strsub.o libft/ft_strcat.o libft/ft_memdel.o libft/ft_strdel.o libft/ft_putendl_fd.o libft/ft_strnstr.o libft/ft_memcpy.o libft/ft_strncat.o libft/ft_strlcat.o libft/ft_memccpy.o libft/ft_strtrim.o libft/ft_atoi.o libft/ft_striter.o libft/ft_striteri.o libft/ft_strmap.o libft/ft_strmapi.o libft/ft_memmove.o libft/ft_itoa.o libft/ft_strsplit.o ft_errors.o ft_handle_prompt.o ft_handle_cd.o ft_handle_exit.o ft_handle_echo.o ft_handle_getenv.o ft_handle_path.o ft_handle_setenv.o ft_handle_fork.o ft_make_env_copy.o ft_handle_unsetenv.o get_next_line.o ft_make_env_del.o ft_handle_env.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib  $(LIB)
	gcc $(CFLAGS) main.c $(LIB)  -o $(NAME)

$(OBJ):
	gcc -c $*.c -o $@ $(CFLAGS)
clean:
	rm -f $(OBJ)

fclean: clean 
	make -C libft/ fclean
	rm -f $(NAME) 
	rm -f $(LIB)
re : fclean all 
