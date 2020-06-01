#include "minishell.h"

void	ft_make_env_del(char ***envp)
{
	size_t	ind;

	ind = 0;
	while ((*envp)[ind] != NULL)
		ft_strdel(&(*envp)[ind++]);
	(*envp)[ind] = NULL;
}