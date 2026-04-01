/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:16:39 by finoment          #+#    #+#             */
/*   Updated: 2026/02/09 12:38:47 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_strtab(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	if (tab == NULL || *tab == NULL)
		return ;
	while (i < len && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_word_dup(char const *s, char c, size_t *index)
{
	size_t	start;
	size_t	len;
	char	*word;

	start = *index;
	while (s[start] == c)
		start++;
	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	len = 0;
	while (s[start] && s[start] != c)
		word[len++] = s[start++];
	word[len] = '\0';
	*index = start;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	index;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	index = 0;
	while (i < words)
	{
		tab[i] = ft_word_dup(s, c, &index);
		if (!tab[i])
		{
			ft_free_strtab(tab, words);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
