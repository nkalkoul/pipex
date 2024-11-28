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
}			t_all;

int		ft_fill_all(t_all *all, char **av, char **env, int ac);
char	*ft_searchgood(char **path, char **cmd);
char	**ft_pathfinder(char **env);
void	ft_delivery(char **av, char **path, int *fds, char **env);

#endif