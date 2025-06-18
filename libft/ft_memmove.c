/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:30:44 by jadalid-          #+#    #+#             */
/*   Updated: 2025/01/21 11:30:44 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_str;

	if (!dest && !src)
		return (0);
	p_dst = (unsigned char *)dest;
	p_str = (unsigned char *)src;
	if (p_dst > p_str)
	{
		while (n > 0)
		{
			n--;
			p_dst[n] = p_str[n];
		}
	}
	else
		return (ft_memcpy(dest, src, n));
	return (dest);
}
