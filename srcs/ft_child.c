/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas91 <kalkoul.nassim@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-30 03:36:27 by nas91             #+#    #+#             */
/*   Updated: 2024-11-30 03:36:27 by nas91            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_firschild(t_all *all, int *fds)
{
	int	infile;

	infile = open(all->av[1], O_RDONLY);
	if (infile == -1)
		(perror("Error infile"), ft_error(all, fds));
	if (dup2(infile, STDIN_FILENO) == -1)
		(perror("error dup first"), ft_error(all, fds));
	close(infile);
	if (dup2(fds[1], STDOUT_FILENO) == -1)
		(perror("error dup first"), ft_error(all, fds));
	close(fds[1]);
	close(fds[0]);
}

void	ft_laschild(t_all *all, int *fds, int i)
{
	int	outfile;

	outfile = open(all->av[i + 3], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (outfile == -1)
		(perror("Error outfile"), ft_error(all, fds));
	if (dup2(outfile, STDOUT_FILENO) == -1)
		(perror("error dup last"), ft_error(all, fds));
	close(outfile);
	if (dup2(all->infile, STDIN_FILENO) == -1)
		(perror("error dup last"), ft_error(all, fds));
	close(fds[0]);
	close(fds[1]);
}

void	ft_midchild(t_all *all, int *fds)
{
	if (dup2(all->infile, STDIN_FILENO) == -1)
		(perror("error dup mid"), ft_error(all, fds));
	if (dup2(fds[0], STDOUT_FILENO) == -1)
		(perror("error dup mid"), ft_error(all, fds));
	close(fds[1]);
	close(fds[0]);
	close(all->infile);
}

void	ft_give(t_all *all, int *fds, int i)
{
	if (i == 0)
		ft_firschild(all, fds);
	else if (i == all->nbc - 1)
		ft_laschild(all, fds, i);
	else
		ft_midchild(all, fds);
	if (ft_chemstyle(all, i + 2) == 1)
		ft_error(all, fds);
	char *cmd = "/bin/invalid/";
	if (execve(cmd, all->cmd, all->env) == -1)
	{
		perror("error exec");
		ft_error(all, fds);
	}
}

void	ft_delivery(t_all *all)
{
	int	i;
	int	fds[2];

	i = 0;
	while (i < all->nbc)
	{
		if (i != all->nbc - 1 && pipe(fds) == -1)
			return (ft_putstr_fd("Error fct pipe", 2));
		all->pid[i] = fork();
		if (all->pid[i] == -1)
			return ;
		if (all->pid[i] == 0)
			ft_give(all, fds, i);
		if (all->infile != -1)
			close(all->infile);
		all->infile = fds[0];
		if (i != all->nbc - 1)
			close(fds[1]);
		i++;
	}
}
