
#include "minishell.h"

static void	ft_putstr_if(const char *str)
{
	int ind;

	ind = -1;
	while (str[++ind] != '\0')
	{
		if (ft_isprint(str[ind]))
			write(1, &str[ind], 1);
	}
}

void		ft_handle_echo(char **argv)
{
	int ind;
	int cnt;

	ind = 1;
	if (*argv[1] == '\0')
	{
		ft_putstr("\n");
		return ;
	}
	while (*argv[ind] != '\0')
	{
		cnt = -1;
		while (argv[ind][++cnt] != '\0')
		{
			if (argv[ind][cnt] == '\"')
				argv[ind][cnt] = 127;
		}
		ft_putstr_if(argv[ind++]);
		ft_putstr(" ");
	}
	ft_putstr("\n");
}
