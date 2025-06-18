/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:37:02 by jadalid-          #+#    #+#             */
/*   Updated: 2025/01/31 18:26:41 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_num(int num)
{
	unsigned int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num = -num ;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char	*put_numbers(int num, int count)
{
	char	*str;
	int		i;

	i = count - 1;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (i >= 0 && num != 0)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		count;
	int		num;

	num = n;
	count = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	count = len_num(num);
	if (n < 0)
		count++;
	temp = put_numbers(num, count);
	return (temp);
}

/* int	main(int argc, char **argv)
{
    if (argc != 2)
    {
    	printf("Usage: %s <number>\n", argv[0]);
    	return 1;
    }
    int num = atoi(argv[1]);
    char *str = ft_itoa(num);

	if (str) 
    {
    	printf("Número como cadena: %s\n", str);
		free(str);
    }
    else
    {
    	printf("Error al convertir el número.\n");
    	return 0;
	}
} */
