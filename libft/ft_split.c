/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:27:59 by juanje            #+#    #+#             */
/*   Updated: 2025/01/31 18:27:58 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c);
static char	*get_words( unsigned int	*j, const char	*str, char c);
static	void	free_ft(char **tab, unsigned int i);

static int	count_words(char const *str, char c)
{
	size_t				i;
	unsigned int		words;
	unsigned int		word_flag;

	i = 0;
	words = 0;
	word_flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			word_flag = 0;
		else if (word_flag == 0)
		{
			word_flag = 1;
			words++;
		}
		i++;
	}
	return (words);
}

static char	*get_words(unsigned int	*ptr_j, const char	*str, char c)
{
	unsigned int	i;
	unsigned int	len;
	char			*word;

	i = 0;
	while (str[*ptr_j] == c)
		(*ptr_j)++;
	i = *ptr_j;
	while (str[i] != c && str[i] != '\0')
		i++;
	len = i - *ptr_j;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[*ptr_j];
		i++;
		(*ptr_j)++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_ft(char **tab, unsigned int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;
	unsigned int	words;

	if (!s)
		return (0);
	words = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (i < words)
	{
		tab[i] = get_words(&j, s, c);
		if (!tab[i])
		{
			free_ft(tab, i);
			return (0);
		}
		i++;
	}
	tab[words] = 0;
	return (tab);
}

/* int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Uso: %s <cadena> <delimitador>\n", argv[0]);
        return 1;
    }

    char *cadena = argv[1];
    char c = argv[2][0];

    char **tab = ft_split(cadena, c);
	
    if (tab) {
        for (int i = 0; tab[i] != NULL; i++) {
            printf("Parte %d: %s\n", i, tab[i]);
        }
        for (int i = 0; tab[i] != NULL; i++) {
            free(tab[i]);
        }
        free(tab);
    }

    return 0;
} */