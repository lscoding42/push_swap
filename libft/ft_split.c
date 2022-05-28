/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:38:52 by lhafsi            #+#    #+#             */
/*   Updated: 2021/12/21 16:45:21 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				w++;
			i++;
		}
		if (str[i])
			i++;
	}
	return (w + 1);
}

int	ft_lettercount(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*mystrdup(char const *str, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (ft_lettercount(str, c) + 1));
	if (!word)
		return (0);
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ft_wordcount(s, c));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = mystrdup(&s[i], c);
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		if (s[i])
			i++;
	}
	return (tab[j] = 0, tab);
}
