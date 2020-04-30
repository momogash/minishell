
#include "minishell.h"

char	**ft_make_env_copy(char **envp)
{
	char	**cpy;
	size_t	ind;

	ind = 0;
	while (envp[ind] != NULL)
		ind++;
	cpy = (char **)malloc(sizeof(char *) * (ind + 1));
	ind = -1;
	while (envp[++ind] != NULL)
		cpy[ind] = ft_strdup(envp[ind]);
	cpy[ind] = NULL;
	return (cpy);
}
