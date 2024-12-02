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
	int		i;
	t_all	all;

	if (ac < 5)
		return (ft_putstr_fd("Wrong number of args\nTest with 4 args", 2), 1);
	if (ft_fill(&all, env, av) == 1)
		return (1);
	ft_delivery(&all);
	i = 0;
	while (i < all.nbc)
	{
		waitpid(all.pid[i], NULL, 0);
		printf("\n\nJUDANANANANA\n\n");
		i++;
	}
	free(all.pid);
	return (0);
}
