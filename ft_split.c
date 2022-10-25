/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:19:37 by mboutuil          #+#    #+#             */
/*   Updated: 2022/10/25 02:19:42 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

// static int wordcounter(char *s,char c)
// {
//     int w;
//     int i;
//     while(*s)
//         w++;
//         if(*s)
//         {   
//             while(*s != c)
//             {
//                 s++;
//                 w++;
//             }
//         }
//         else 
//             s++;
//    return w;     
// }
// static int word_scounter(char *s,char c,int n)
// {
//     int i;

//     while(*s != c)
//         {
//             s++;
//             n++;
//         }
//     return n ;
// }
// static void	ft_free(char **strs, int j)
// {
// 	while (j-- > 0)
// 		free(strs[j]);
// 	free(strs);
// }
// char		**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		word;
// 	char	**strs;
// 	int		size;
// 	int		j;

// 	i = 0;
// 	j = -1;
// 	word = wordcounter(s, c);
// 	if (!(strs = (char **)malloc((word + 1) * sizeof(char *))))
// 		return (NULL);
// 	while (++j < word)
// 	{
// 		while (s[i] == c)
// 			i++;
// 		size = word_scounter(s, c, i);
// 		if (!(strs[j] = ft_substr(s, i, size)))
// 		{
// 			ft_free(strs, j);
// 			return (NULL);
// 		}
// 		i += size;
// 	}
// 	strs[j] = 0;
// 	return (strs);
// }

static int	ft_count_word(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	if (!(strs = (char **)malloc((word + 1) * sizeof(char *))))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		if (!(strs[j] = ft_substr((char *)s, i, size)))
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}