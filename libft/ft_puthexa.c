/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:39:57 by nas91             #+#    #+#             */
/*   Updated: 2024/11/19 23:50:13 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase(unsigned long nb, char *base)
{
	size_t	lenb;
	int		count;

	count = 0;
	lenb = ft_strlen(base);
	if (nb >= (unsigned long)lenb)
	{
		count += ft_putnbrbase(nb / lenb, base);
		count += ft_putnbrbase(nb % lenb, base);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	vaddr;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	vaddr = (unsigned long long)ptr;
	count += write(1, "0x", 2);
	count += ft_putnbrbase(vaddr, "0123456789abcdef");
	return (count);
}

int	ft_puthex(unsigned int nb, char format)
{
	int	count;

	count = 0;
	if (format == 'x')
		count += ft_putnbrbase(nb, "0123456789abcdef");
	if (format == 'X')
		count += ft_putnbrbase(nb, "0123456789ABCDEF");
	return (count);
}
