/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:41:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/05 10:20:51 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL2_H
# define FT_MINISHELL2_H

# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define PROT PROT_NONE,PROT_READ,PROT_WRITE,PROT_EXEC
# define MAP MAP_ANON,MAP_FILE,MAP_FIXED,MAP_PRIVATE,MAP_NOCACHE

void		*ft_malloc(size_t size);
size_t		tiny_size(void);
void		ft_nope(void);

#endif
