
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

static char		**ft_remove_env(char **envp, int index)
{
	char	**cpy;
	int		ind;
	int		cnt;

	ind = 0;
	cnt = 0;
	while (envp[ind] != NULL)
		ind++;
	cpy = (char **)malloc(sizeof(char *) * (ind + 1));
	ind = -1;
	while (envp[++ind] != NULL)
	{
		if (ind != index)
			cpy[ind - cnt] = ft_strdup(envp[ind]);
		else
			cnt++;
	}
	ft_strdel(envp);
	cpy[ind - cnt] = NULL;
	return (cpy);
}

int				ft_handle_unsetenv(char ***envp, const char *name)
{
	int index;

	if (!name || *envp == NULL)
		return (0);
	index = ft_get_index(*envp, name);
	if (index != -1)
		*envp = ft_remove_env(*envp, index);
	return (1);
}
