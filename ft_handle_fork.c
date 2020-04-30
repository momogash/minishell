
#include "minishell.h"

//System call fork() is used to creat processes. it takes no
//arguments and returns a process ID. the purpose of fork() is 
//to create a new child process
//if fork() returns a nagative value, the creation of a child
//process was unsuccessful.
//fork() returns a zero to the newly created  child process.
//fork() returns a positive value, the process ID of the child process,
//to the parent

static void		ft_handle_builtin(char **argv, char ***envp)
{
	if (ft_strcmp(argv[0], "cd") == 0)
		ft_handle_cd(envp, argv);
	if (ft_strcmp(argv[0], "env") == 0)
		ft_handle_env(*envp);
	if (ft_strcmp(argv[0], "echo") == 0)
		ft_handle_echo(argv);
	if (ft_strcmp(argv[0], "getenv") == 0)
		ft_putendl(ft_handle_getenv(*envp, argv[1]));
	if (ft_strcmp(argv[0], "setenv") == 0)
		ft_handle_setenv(envp, argv[1], argv[2], 0);
	if (ft_strcmp(argv[0], "unsetenv") == 0)
		ft_handle_unsetenv(envp, argv[1]);
}

// Function to execute builtin commands 
static int		ft_is_builtin(char **argv)
{
	int b;

	b = 0;
	if (ft_strcmp(argv[0], "cd") == 0)
		b = 1;
	else if (ft_strcmp(argv[0], "env") == 0)
		b = 1;
	else if (ft_strcmp(argv[0], "echo") == 0)
		b = 1;
	else if (ft_strcmp(argv[0], "setenv") == 0)
		b = 1;
	else if (ft_strcmp(argv[0], "getenv") == 0)
		b = 1;
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
		b = 1;
	else if (ft_strcmp(argv[0], "exit") == 0)
		b = 1;
	return (b);
}

static void		ft_run_child(char ***envp, char **argv)
{
	char *temp;
	char *ind;

	temp = NULL;
	if ((ind = ft_handle_path(envp, argv)) != NULL)
	{
		temp = ft_strjoin(ind, argv[0]);
		if ((execve(temp, &argv[0], *envp)) == -1)
			ft_error(CMDE, argv[0]);
	}
	else if (ft_strncmp(argv[0], "/bin/", 4) == 0)
	{
		if ((execve(argv[0], &argv[0], *envp)) == -1)
			ft_error(CMDE, argv[0]);
	}
	else
		ft_error(CMDE, argv[0]);
	ft_strdel(&ind);
	ft_strdel(&temp);
}

//if the call to fork() is executed successfully, Unixn will
//make two identical copies of address spaces, one for the 
//parent and one for the child
//both processes will start their execution
//both processes have identical but separate address spaces  
void			ft_handle_fork(char **argv, char ***envp)
{
	pid_t pid;

	if (ft_is_builtin(argv) == 1)
		ft_handle_builtin(argv, envp);
	else
	{
		// Forking a child 
		pid = fork();
		if (pid == 0)
		{
			ft_run_child(envp, argv);
			ft_handle_exit();
		}
		else if (pid < 0)
			ft_putstr("Falied to fork process:\n");
		else
			// waiting for child to terminate 
			wait(NULL);
	
}
