#include "minishell.h"

char		*ft_handle_getenv(char **envp, const char *name)
{
	int ind;
	int cntr;

	ind = 0;
	if (envp == NULL)
	{
		ft_putstr("No environment\n");
		return (NULL);
	}
	if (name == NULL)
		return (NULL);
	while (envp[ind] != NULL)
	{
		cntr = 0;
		while (envp[ind][cntr] && name[cntr] && envp[ind][cntr] == name[cntr])
		{
			if (envp[ind][cntr + 1] == '\0')
			return NULL;
			if (envp[ind][cntr + 1] == '='){
				return (ft_strdup(ft_strchr(envp[ind] + cntr, '=') + 1));
			}
			cntr++;
		}
		ind++;
	}
	return (NULL);
}