#include "minishell.h"

static void		ft_remove_qoute(char **cmd)
{
	int ind;

	ind = -1;
	if (*cmd)
	{
		while ((*cmd)[++ind] != '\0')
		{
			if ((*cmd)[ind] == '\"')
				(*cmd)[ind] = 32;
		}
	}
}

static void		ft_handle_cmd(char *cmd, char ***envp)
{
	char **argv;

	if (cmd == NULL || !*cmd)
		return ;
	ft_remove_qoute(&cmd);
	cmd = ft_strtrim(cmd);
	if (cmd == NULL || !*cmd)
		return ;
	argv = ft_strsplit(cmd, ' ');
	if (!argv[0] && !*argv[0])
		return ;
	if (ft_strcmp(argv[0], "exit") == 0)
	{
		ft_handle_exit();
		ft_make_env_del(&argv);
	}
	ft_handle_fork(argv, envp);
	ft_make_env_del(&argv);
	free(cmd);
	int i = 0;
	// ft_putstr("Handling the command");
	while (argv[i] != NULL){
		ft_putstr(argv[i]);
		free(argv[i++]);
	}
	free(argv);
}

void			ft_handle_prompt(char ***envp)
{
	char *cmd;

	cmd = NULL;
	ft_putstr("$>");
	while (get_next_line(0, &cmd))
	{
		ft_handle_cmd(cmd, envp);
		if(cmd)
			free(cmd);
		ft_putstr("$>");
	}
}
