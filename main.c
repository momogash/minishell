#include "minishell.h"
#include <stdio.h>

int		main(int argc, char **argv, char **envp)
{
	char	**cenvp;

	if (argc < 1)
		return (-1);
	if (envp == NULL)
		ft_putstr("No enviroment value\n");
	(void)argv;
	cenvp = ft_make_env_copy(envp);
	ft_handle_prompt(&cenvp);
	ft_make_env_del(&cenvp);
	
	int i = 0;
	while (cenvp[i] != NULL){
		ft_putendl(cenvp[i]);
		free(cenvp[i]);
		i++;
	}
	free(cenvp);
	return (0);
}