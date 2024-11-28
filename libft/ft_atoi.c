/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 02:10:26 by nas91             #+#    #+#             */
/*   Updated: 2024/11/06 16:41:51 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *s1)
{
	int		i;
	long	nbr;
	int		sign;

	sign = 1;
	i = 0;
	nbr = 0;
	while (((s1[i] >= 9 && s1[i] <= 13) || s1[i] == 32) && s1[i])
		i++;
	if (s1[i] == '-' || s1[i] == '+')
	{
		if (s1[i] == '-')
			sign = -1;
		i++;
	}
	while (s1[i] && ft_isdigit(s1[i]) == 1)
	{
		nbr = 10 * nbr + (s1[i] - 48);
		i++;
		if (s1[i] && ft_isdigit(s1[i]) == 0)
			return (2147483648);
	}
	return (nbr * sign);
}
