/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:41:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/06 17:14:58 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL2_H
# define FT_MINISHELL2_H

# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define	ALLOC_FLAGS	MAP_PRIVATE | MAP_ANON

void		free(void *ptr);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		*ft_malloc(size_t size);
size_t		tiny_size(void);
size_t		small_size(void);
size_t		large_size(void);
void		ft_nope(void);
void		show_alloc_mem(); // ??

#endif
