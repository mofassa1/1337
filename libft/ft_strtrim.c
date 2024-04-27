/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:05:33 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/18 01:50:06 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_c_instr(const char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	int		start;
	int		end;

	start = 0;
	while (s1 && s1[start] && is_c_instr(set, s1[start]))
		start++;
	if (!s1 || !s1[start])
	{
		new_s = (char *)malloc(sizeof(char));
		if (!new_s)
			return (NULL);
		new_s[0] = '\0';
		return (new_s);
	}
	end = ft_strlen((char *)s1) - 1;
	while (end > 0 && is_c_instr(set, s1[end]))
				end--;
		new_s = (char *)malloc(end - start + 2);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, &s1[start], (end - start) + 2);
	return (new_s);
}

// ---------------

// static int	is_c_instr(const char *str, char c)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		if (str[i] == c)
// 			return (1);
// 	return (0);
// }

// static char	*return_null(char const *s1, char const *set)
// {
// 	if (!s1)
// 		return (NULL);
// 	if (!set)
// 		return ((char *)s1);
// 	return (NULL);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*new_s;
// 	int		start;
// 	int		end;

// 	if (!s1 || !set)
// 		return (return_null(s1, set));
// 	start = 0;
// 	while (s1[start] && is_c_instr(set, s1[start]))
// 		start++;
// 	if (!s1[start])
// 	{
// 		new_s = (char *)malloc(sizeof(char));
// 		if (!new_s)
// 			return (NULL);
// 		new_s[0] = '\0';
// 		return (new_s);
// 	}
// 	end = ft_strlen((char *)s1) - 1;
// 	while (end > 0 && is_c_instr(set, s1[end]))
// 				end--;
// 		new_s = (char *)malloc(end - start + 2);
// 	if (!new_s)
// 		return (NULL);
// 	ft_strlcpy(new_s, &s1[start], (end - start) + 2);
// 	return (new_s);
// }