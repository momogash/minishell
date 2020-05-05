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
	binfiles = ft_strsplit(path, ':');
	(path != NULL) ? ft_strdel(&path) : NULL;
	while (binfiles[++ind] != NULL)
	{
		temp = ft_strjoin(binfiles[ind], "/");
		if ((dir = opendir(temp)) == NULL)
		{
			//ft_error();
			free(temp);
			free(dir);
			return (0);
		}
		while ((dr = readdir(dir)) != NULL)
		{
			if (ft_strcmp(dr->d_name, argv[0]) == 0){
				free(dr);
				if (dir)
					free(dir);
				return (temp);

			}
		}
		// ft_strdel(&temp);
		free(temp);
		free(dir);
			// ft_putendl("Are you here");
	}
	int i = 0;
	while (binfiles[i] != NULL)
	{
		ft_putstr(binfiles[i]);
		free(binfiles[i++]);
	}
	free(binfiles);
	return (NULL);
}
