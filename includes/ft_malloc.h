/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:41:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/09 11:36:13 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL2_H
# define FT_MINISHELL2_H

# include <stdio.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <sys/time.h> 
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "../libft/libft.h"

# define	ALLOC_FLAGS	MAP_PRIVATE | MAP_ANON
# define	TINY 512
# define	SMALL 10240
# define	LARGE 204800

enum				Boolean 
{ 
					false, 
					true 
}; 

typedef struct		s_block
{
	short			is_free;
	void			*next;
}					t_block;

typedef struct		s_page
{
	short			type;	// TINY = 400*512 / SMALL = 20*10240 / LARGE = 1*204800
	void			*next;
	struct s_block	*first;
	int				nb_block;	// 1 bloc = 1 malloc
}					t_page;

extern t_page		g_page;

void		free(void *ptr);
void		ft_free(void *ptr);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		*ft_malloc(size_t size);
void		*get_mem(short flag, size_t size);
size_t		tiny_size(void);
size_t		small_size(void);
size_t		large_size(void);
size_t		get_page_size(size_t size);
void		ft_nope(void);
void		show_alloc_mem(); // ??
void		ft_atoi_hex(void *ptr);

#endif
