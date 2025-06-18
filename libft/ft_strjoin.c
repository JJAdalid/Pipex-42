/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:48:53 by jadalid-          #+#    #+#             */
/*   Updated: 2025/02/13 20:23:48 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	size_t			leng;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	leng = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (leng + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
