/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:46:54 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/18 13:49:07 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char c)
{
	int		nb_words;
	int		i;
	char	prev_char;

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
	return (nb_words);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**fill_resulting_array(char **result_array, char *str, char c)
{
	int	i;
	int	wstart;
	int	wend;
	int	word;

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
				return (NULL);
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
	int		word;

	nb_words = count_words(str, c);
	if (!str)
		return (NULL);
	if (nb_words == 0)
		return (NULL);
	result_array = malloc(sizeof(char *) * (nb_words + 1));
	if (!result_array)
		return (NULL);
	if (!fill_resulting_array(result_array, str, c))
	{
		word = 0;
		while (result_array[word])
			free(result_array[word++]);
		free(result_array);
		return (NULL);
	}
	return (result_array);
}
