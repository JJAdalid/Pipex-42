/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:49:20 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/20 14:20:19 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, size_t	*count)
{
	char	num;

	if (n == -2147483648)
	{
		(*count) += write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*count) += 1;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
	}
	num = (n % 10) + '0';
	(*count) += write (1, &num, 1);
}

void	ft_putnbr_base(unsigned long n, char *base, size_t *count)
{
	unsigned int	base_len;
	char			num;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base, count);
	}
	num = base[n % base_len];
	(*count) += write(1, &num, 1);
}

void	ft_put_ptr(void *ptr, size_t *count)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	if (n == 0)
	{
		(*count) += write(1, "(nil)", 5);
		return ;
	}
	(*count) += write(1, "0x", 2);
	ft_putnbr_base(n, "0123456789abcdef", count);
}
