#include "minishell.h"

static int		ft_get_index(char **envp, const char *name)
{
	int ind;
	int cntr;

	ind = 0;
	cntr = 0;
	if (envp == NULL)
		ft_putstr("No environment :\n");
	while (envp[ind] != NULL)
	{
		while (envp[ind][cntr] && name[cntr] && envp[ind][cntr] == name[cntr])
		{
			if (envp[ind][cntr + 1] == '=')
				return (ind);
			cntr++;
		}
		ind++;
	}
	return (-1);
}

static char		**ft_add_env(char **envp, char *value)
{
	char	**cpy;
	size_t	ind;

	ind = 0;
	while (envp[ind] != NULL)
		ind++;
	cpy = (char **)malloc(sizeof(char *) * (ind + 2));
	ind = -1;
	while (envp[++ind] != NULL)
		cpy[ind] = ft_strdup(envp[ind]);
	cpy[ind++] = ft_strdup(value);
	cpy[ind] = NULL;
	ft_make_env_del(&envp);
	free(cpy[ind]);
	return (cpy);
}

int				ft_handle_setenv(char ***envp, \
const char *name, const char *value, int overwrite)
{
	int		index;
	char	*temp;
	char	*hold;
	if (!*name || !*value)
		return (0);
	index = ft_get_index(*envp, name);
	temp = ft_strdup(name);
	hold = temp;

	temp = ft_strjoin(hold, "=");
	free(hold);
	hold = temp;
	temp = ft_strjoin(temp, value);
	(hold != NULL) ? ft_strdel(&hold) : NULL;
	free(hold);
	
	if (index == -1 || overwrite == 0)
		*envp = ft_add_env(*envp, temp);
	else if (index != -1 && overwrite)
		(*envp)[index] = ft_strdup(temp);
	free(temp);
	return (1);
}