/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:46:54 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/17 14:41:27 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char c)
{
	int	nb_words;
	int	i;
	char prev_char;
	
	nb_words = 0;
	i = 0;
	prev_char = c;
	while (str[i])
	{
		if (str[i] != c && prev_char == c)
			nb_words++;
		prev_char = str[i];
		i++;
	}
	return(nb_words);
}

char *ft_strncpy(char *dest, char *src, int n)
{
	int	i;
	
	i = 0;
	while(src[i] && i < n) 
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**fill_resulting_array(char **resulting_array, char *str, char c)
{
	int		i;
	int	word_start;
	int	word_end;
	int	word;
	
	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		word_start = i;
		while (str[i] != c && str[i])
			i++;
		word_end = i;
		if (word_start < word_end)
		{
			resulting_array[word] = (char *)malloc(sizeof(char) * ((word_end - word_start) + 1));
			if (!resulting_array [word])
				return (NULL);
			ft_strncpy(resulting_array[word++], &str[word_start], (word_end - word_start));
		}
	}
	resulting_array[word] = NULL;
	return (resulting_array);
}

char	**split(char *str, char c)
{
	int	nb_words;
	char	**resulting_array;
	int word;
	
	nb_words = count_words(str, c);
	if (!str)
		return (NULL);
	if (nb_words == 0)
		return (NULL);
	resulting_array = malloc(sizeof(char *) * (nb_words + 1));
	if (!resulting_array)
		return (NULL);
	if (!fill_resulting_array(resulting_array, str, c))
	{
		word = 0;
		while (resulting_array[word])
			free(resulting_array[word++]);
		free(resulting_array);
		return(NULL);
	}
	return (resulting_array);
}
