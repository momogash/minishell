
#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char	**cenvp;

	if (argc < 1)
		return (-1);
	if (envp == NULL)
		ft_putstr("No enviroment value\n");
	(void)argv;
	//ft_handle_path(&envp, argv);
	cenvp = ft_make_env_copy(envp);
	ft_handle_prompt(&cenvp);
	ft_make_env_del(&cenvp);
	return (0);
}
