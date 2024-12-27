/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:46:54 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/27 16:22:23 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int		nb_words;
	int		i;

	nb_words = 0;
	i = 0;
	while (str[i])
	{
		while(str[i] == c)
			i++;
		if (str[i])
		{
			nb_words++;
			while (str[i] != c && str[i])
				i++;
		}	
	}
	return (nb_words);
}

static char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**free_result_array(char **result_array, int word)
{
    int	i;

	i = 0;
	while (i < word)
	{
		free(result_array[i]);
		i++;
	}
    free(result_array);
    return (NULL);
}

static char	**fill_resulting_array(char **result_array, char *str, char c)
{
	int	i;
	int	wstart;
	int	wend;
	static int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		wstart = i;
		while (str[i] != c && str[i])
			i++;
		wend = i;
		if (wstart < wend)
		{
			result_array[word] = malloc(sizeof(char) * ((wend - wstart) + 1));
			if (!result_array [word])
				return free_result_array(result_array, word);
			ft_strncpy(result_array[word++], &str[wstart], (wend - wstart));
		}
	}
	result_array[word] = NULL;
	return (result_array);
}

char	**split(char *str, char c)
{
	int		nb_words;
	char	**result_array;

	if (!str)
		return (NULL);
	nb_words = count_words(str, c);
	if (nb_words == 0)
		return (NULL);
	result_array = malloc(sizeof(char *) * (nb_words + 1));
	if (!result_array)
		return (NULL);
	if (!fill_resulting_array(result_array, str, c))
		return (NULL);
	return (result_array);
}
