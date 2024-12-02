/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas91 <kalkoul.nassim@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 23:39:46 by nas91             #+#    #+#             */
/*   Updated: 2024-11-26 23:39:46 by nas91            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>

typedef struct s_all
{
	char	**av;
	char	**env;
	int		ac;
	int		nbc;
	char	*chem;
	char	**cmd;
	int		*pid;
	int		infile;
}			t_all;

char	*ft_searchgood(char **cmd, char **env);
char	**ft_pathfinder(char **env);
void	ft_delivery(t_all *all);
int		ft_chemstyle(t_all *all, int i);
int		ft_fill(t_all *all, char **env, char **av);

#endif