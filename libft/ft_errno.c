/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:59:58 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/06 15:32:29 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stddef.h>
#include <unistd.h>

char	*ft_error(int errnum)
{
	char						*ret;
	extern const char *const	sys_errlist[];
	extern const int			sys_nerr;

	if (errnum < 0 || errnum >= sys_nerr)
	{
		errno = EINVAL;
		return (ft_strjoin("Error ID = ", ft_itoa(errnum)));
	}
	ret = (char*)sys_errlist[errnum];
	return (ret);
}

void	ft_perror(const char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
		write(2, " :", 2);
	}
	write(2, ft_error(errno), ft_strlen(ft_error(errno)));
	write(2, "\n", 1);
}
