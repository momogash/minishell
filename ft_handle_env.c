#include "minishell.h"

void		ft_handle_env(char **envp)
{
	int ind;

	ind = 0;
	while (envp[ind] != NULL)
		ft_putendl(envp[ind++]);
}