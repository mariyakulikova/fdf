/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:17:39 by mkulikov          #+#    #+#             */
/*   Updated: 2023/11/22 11:41:12 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;
	size_t	substrlen;

	if (NULL == s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	substrlen = strlen - start;
	if (len > substrlen)
		len = substrlen;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
