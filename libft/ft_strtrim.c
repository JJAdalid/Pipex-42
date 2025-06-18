/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:26:16 by jadalid-          #+#    #+#             */
/*   Updated: 2025/01/24 20:40:11 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	while (ft_strchr(set, s1[j]) && s1[i] != '\0')
		j--;
	dest = ft_substr(s1, (unsigned int)i, (j - i + 1));
	return (dest);
}
