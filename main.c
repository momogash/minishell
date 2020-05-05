
#include "minishell.h"
#include <stdio.h>

int		main(int argc, char **argv, char **envp)
{
	char	**cenvp;

	if (argc < 1)
		return (-1);
	if (envp == NULL)
		ft_putstr("No enviroment value\n");
		// printf("There was an error");
	(void)argv;
	//ft_handle_path(&envp, argv);
	cenvp = ft_make_env_copy(envp);
	ft_handle_prompt(&cenvp);
	ft_make_env_del(&cenvp);
	free(cenvp);
	return (0);
}
