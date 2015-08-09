/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:41:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/09 17:57:26 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdio.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "../libft/libft.h"

# define FLAGS PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON
# define TINY 1024
# define TINY_PAGE 204800
//# define SMALL 10240
//# define LARGE 204800

enum				s_bool
{
	false,
	true
}					t_bool;

typedef struct		s_tiny
{
	short			allocation;
	void			*page;
	void			*next;
}					t_tiny;

typedef struct		s_small
{
	short			allocation;
	void			*next;
}					t_small;

typedef struct		s_large
{
	short			allocation;
	void			*next;
}					t_large;

typedef struct		s_page
{
	t_tiny			*tiny_head;
	t_small			*small_head;
	t_large			*large_head;
	int				nb_block;
}					t_page;

extern t_page		g_page;

void				free(void *ptr);
void				ft_free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				*ft_malloc(size_t size);
void				*get_mem(short flag, size_t size);
void				*ft_tiny_search(t_tiny *page);
t_tiny				*ft_new_tiny(void);
t_tiny				*ft_tiny_find(t_tiny *tiny_head);
t_small				*ft_new_small(void);
t_large				*ft_new_large(void);
size_t				tiny_size(void);
size_t				small_size(void);
size_t				large_size(void);
size_t				get_page_size(size_t size);
void				ft_nope(void);
void				show_alloc_mem();
void				ft_atoi_hex(void *ptr);

#endif
