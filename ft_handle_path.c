#include "minishell.h"
#include <stdio.h>

char		*ft_handle_path(char ***envp, char **argv)
{
	char			**binfiles;
	char			*path;
	int				ind;
	DIR				*dir;
	char			*temp;
	struct dirent	*dr;

	ind = 0;
	path = ft_handle_getenv(*envp, "PATH");
	if (path == NULL)
		return (NULL);
	binfiles = ft_strsplit(path, ':');
	(path != NULL) ? ft_strdel(&path) : NULL;
	while (binfiles[++ind] != NULL)
	{
		temp = ft_strjoin(binfiles[ind], "/");
		if ((dir = opendir(temp)) == NULL)
		{
			free(temp);
			free(dir);
			return (0);
		}
		while ((dr = readdir(dir)) != NULL)
		{
			if (ft_strcmp(dr->d_name, argv[0]) == 0)
			{
				if (dir)
				{
					free(dir);
				}
				return (temp);
			}
		}
		free(temp);
		free(dir);
	}
	int i = 0;
	while (binfiles[i] != NULL)
	{
		free(binfiles[i++]);
	}
	free(binfiles);
	return (NULL);
}