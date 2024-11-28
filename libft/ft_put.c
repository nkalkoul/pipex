/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:23:48 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/19 23:50:04 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putintd(va_list carg)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(va_arg(carg, int));
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

int	ft_putc(va_list carg)
{
	ft_putchar_fd(va_arg(carg, int), 1);
	return (1);
}

int	ft_puts(char *str)
{
	int		count;

	if (!str)
		return (write(1, "(null)", 6));
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (count);
}

int	ft_putu(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putu(n / 10);
	count++;
	ft_putchar_fd((n % 10) + '0', 1);
	return (count);
}
