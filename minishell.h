
#ifndef __MINISHELL_H
# define __MINISHELL_H
# include "get_next_line.h"
# include "libft/libft.h"
# include <sys/wait.h>
# include <dirent.h>
# define NDIR 1
# define CMDE 2

char 	**ft_make_env_copy(char **envp);
void 	ft_handle_prompt(char ***envp);
void 	ft_handle_env(char **envp);
int 	ft_handle_setenv(char ***envp, const char *name, const char *value, int overwrite);
int 	ft_handle_unsetenv(char ***envp, const char  *name);
char 	*ft_handle_getenv(char **envp, const char *name);
void 	ft_handle_fork(char **argv, char ***envp);
void 	ft_handle_exit(void);
void 	ft_handle_cd(char ***envp, char **argv);
void 	ft_error(int error, char *name);
void 	ft_handle_echo(char ** argv);
char 	*ft_handle_path(char ***envp, char **argv);
void	ft_make_env_del(char ***envp);

#endif
