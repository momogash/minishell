#include "minishell.h"

void		ft_error(int error, char *name)
{
	if (error == NDIR)
	{
		ft_putstr("cd: no such file or directory : ");
		ft_putendl(name);
	}
	else if (error == CMDE)
	{
		ft_putstr("zsh : command not found: ");
		ft_putendl(name);
	}
}