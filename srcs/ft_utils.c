/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas91 <kalkoul.nassim@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-27 00:29:24 by nas91             #+#    #+#             */
/*   Updated: 2024-11-27 00:29:24 by nas91            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_fill_all(t_all *all, char **av, char **env, int ac)
{
	all->ac = ac;
	all->av = av;
	all->env = env;
	all->nbc = ac - 3;
	return (0);
}

char	**ft_pathfinder(char **env)
{
	int		i;
	char	*new;
	char	**fin;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			new = ft_strdup(env[i] + 5);
			if (!new)
				return (NULL);
			fin = ft_split(new, ':');
			if (!fin)
				return (free(new), NULL);
			return (fin);
		}
		i++;
	}
	return (perror("pas de search"), NULL);
}

char	*ft_searchgood(char **path, char **cmd)
{
	int		i;
	char	*new;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	while (path[i])
	{
		new = ft_re_strjoin(path[i], "/");
		if (!new)
			return (NULL);
		new = ft_re_strjoin(new, cmd[0]);
		if (!new)
			return (NULL);
		if (access(new, X_OK) == 0)
			return (new);
		free(new);
		i++;
	}
	return (perror("pas de shlass"), NULL);
}

void	ft_delivery(char **av, char **path, int *fds, char **env)
{
	pid_t	forking;
	int		fdfile;
	char	*chem;
	char	**cmd;

	forking = fork();
	if (forking == 0)
	{
		fdfile = open(av[1], O_CREAT | O_RDWR, 0644);
		dup2(fdfile, STDIN_FILENO);
		close(fdfile);
		cmd = ft_split(av[2], ' ');
		chem = ft_searchgood(path, cmd);
		execve(chem, cmd, env);
	}
	else if (forking != 0)
		waitpid(forking, NULL, 0);
}
