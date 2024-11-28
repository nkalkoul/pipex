/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 00:49:38 by nas91             #+#    #+#             */
/*   Updated: 2024/05/31 18:14:53 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ncount, size_t siz)
{
	void	*ptr;

	ptr = malloc(siz * ncount);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, ncount * siz);
	return (ptr);
}
