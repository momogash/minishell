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
	return (cpy);
}

int				ft_handle_setenv(char ***envp, \
const char *name, const char *value, int overwrite)
{
	int		index;
	char	*temp;
	char	*hold;
	char	**del_tmp;
	char 	*str_to_del;

	if (!*name || !*value)
		return (0);
	index = ft_get_index(*envp, name);
	temp = ft_strdup(name);
	hold = temp;

	temp = ft_strjoin(hold, "=");
	free(hold);
	hold = temp;
	temp = ft_strjoin(temp, value);
	// (hold != NULL) ? ft_strdel(&hold) : NULL;
	if (hold != NULL)
	free(hold);
	
	if (index == -1 || overwrite == 0)
	{
		del_tmp = *envp;
		*envp = ft_add_env(*envp, temp);
		int i = 0;
		while(del_tmp[i] != NULL){
			free(del_tmp[i++]);
		}
		free(del_tmp);
	}
	else if (index != -1 && overwrite)
	{
		str_to_del = (*envp)[index];
		(*envp)[index] = ft_strdup(temp);
		free(str_to_del);
	}
	free(temp);
	return (1);
}