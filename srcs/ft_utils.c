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

	i = 0;
	path = ft_pathfinder(env);
	if (!path)
		return (NULL);
	if (access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	while (path[i])
	{
		new = ft_re_strjoin(path[i], "/");
		if (!new)
			return (ft_free_double(path), NULL);
		new = ft_re_strjoin(new, cmd[0]);
		if (!new)
			return (ft_free_double(path), NULL);
		if (access(new, X_OK) == 0)
			return (new);
		free(new);
		i++;
	}
	free(path);
	return (perror("Error8"), NULL);
}

int	ft_chemstyle(t_all *all, int i)
{
	all->cmd = ft_split(all->av[i], ' ');
	if ((all->cmd) == NULL)
		return (1);
	all->chem = ft_searchgood(all->cmd, all->env);
	if ((all->chem) == NULL)
		return (ft_free_double(all->cmd), 1);
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