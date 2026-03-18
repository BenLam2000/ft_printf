/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:49:05 by belam             #+#    #+#             */
/*   Updated: 2025/10/30 03:56:32 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	word_count;

	word_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word_count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word_count);
}

// dep: malloc
// 'break' prevents scenario s[i] == NULL, enters last if, 
// and malloc 2nd time, hence lost bytes if s ends with c, ex: "ab c ", 
// allocate 2 bytes twice at c and '\0'
static char	**ft_count_malloc_chars(char **strs, const char *s, char c)
{
	int	w_count;
	int	c_count;
	int	i;

	w_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		w_count++;
		c_count = 0;
		while (s[i] != c && s[i] != '\0')
		{
			c_count++;
			i++;
		}
		strs[w_count - 1] = (char *)malloc((c_count + 1) * sizeof(char));
		if (!(strs[w_count - 1]))
			return (NULL);
	}
	strs[w_count] = NULL;
	return (strs);
}

// dep: ft_is_new_word, ft_is_char_count
static void	ft_split_strcpy(char **strs, const char *s, char c)
{
	int	i;
	int	w_count;
	int	c_count;

	w_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			w_count++;
			c_count = 0;
		}
		while (s[i] != c && s[i] != '\0')
		{
			strs[w_count - 1][c_count] = s[i];
			c_count++;
			i++;
		}
		if (w_count > 0)
			strs[w_count - 1][c_count] = '\0';
	}
}

// dep: malloc, ft_count_words, ft_count_malloc_chars, ft_split_strcpy
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		word_count;

	word_count = ft_count_words(s, c);
	strs = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs = ft_count_malloc_chars(strs, s, c);
	if (!strs)
		return (NULL);
	if (word_count > 0)
		ft_split_strcpy(strs, s, c);
	return (strs);
}
