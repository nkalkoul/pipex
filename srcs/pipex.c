/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas91 <kalkoul.nassim@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 23:38:39 by nas91             #+#    #+#             */
/*   Updated: 2024-11-26 23:38:39 by nas91            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	t_all	all;
	int		fds[2];
	char	**path;
	int		i;

	i = 0;
	if (ac  != 3)
		return (perror("Wrong number of args\nTest with 4 args"), 1);
	if (ft_fill_all(&all, av, env, ac) == 1)
		return (1);
	path = ft_pathfinder(env);
	ft_delivery(av, path, fds, env);
}
