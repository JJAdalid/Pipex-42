/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:13:50 by jadalid-          #+#    #+#             */
/*   Updated: 2025/01/23 17:30:05 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;

	if (!dst && !src)
	{
		return (0);
	}
	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	while (n--)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
	}
	return (dst);
}
