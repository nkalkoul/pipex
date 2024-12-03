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
			return (free(new), fin);
		}
		i++;
	}
	return (perror("pas de search"), NULL);
}

char	*ft_searchgood(char **cmd, char **env)
{
	int		i;
	char	*new;
	char	**path;

	i = -1;
	path = ft_pathfinder(env);
	if (!path)
		return (NULL);
	if (access(cmd[0], X_OK) == 0)
		return (ft_free_double(path), ft_strdup(cmd[0]));
	while (path[++i])
	{
		new = ft_strjoin(path[i], "/");
		if (!new)
			return (ft_free_double(path), NULL);
		new = ft_re_strjoin(new, cmd[0]);
		if (!new)
			return (ft_free_double(path), NULL);
		if (access(new, X_OK) == 0)
			return (ft_free_double(path), new);
		free(new);
	}
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(" : command not found\n", 2);
	return (ft_free_double(path), NULL);
}

int	ft_chemstyle(t_all *all, int i)
{
	all->cmd = ft_split(all->av[i], ' ');
	if ((all->cmd) == NULL)
		return (1);
	if (all->cmd[0] == NULL)
		return (ft_putstr_fd("Empty cmd\n", 2), 1);
	all->chem = ft_searchgood(all->cmd, all->env);
	if ((all->chem) == NULL)
		return (ft_free_double(all->cmd), all->cmd = NULL, 1);
	return (0);
}

int	ft_fill(t_all *all, char **env, char **av)
{
	all->cmd = NULL;
	all->chem = NULL;
	all->env = env;
	all->av = av;
	all->infile = -1;
	all->nbc = ft_countdouble(av) - 3;
	all->pid = malloc(sizeof(int) * (all->nbc));
	if (!all->pid)
		return (ft_putstr_fd("problem malloc", 2), 1);
	return (0);
}

void	ft_error(t_all *all, int *fds)
{
	if (fds && fds[0] > 0)
		close(fds[0]);
	if (fds && fds[1] > 0)
		close (fds[1]);
	if (all->infile > 0)
		close(all->infile);
	if (all->pid)
		free(all->pid);
	if (all->chem)
		free(all->chem);
	if (all->cmd)
		ft_free_double(all->cmd);
	exit(1);
}
