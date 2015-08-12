/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:41:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 18:47:12 by cdeniau          ###   ########.fr       */
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
# define FLAGS2 PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON
# define TINY 512
# define TINY_PAGE 102400  // max 200 TINY
# define SMALL 4096
# define SMALL_PAGE 409600  // max 100 SMALL

typedef struct		s_header
{
	void			*next_block;
	int				current_size;
	int				flag;
}					t_header;

typedef struct		s_tiny
{
	t_header		*page;
	void			*next;
}					t_tiny;

typedef struct		s_small
{
	int				tsize;
	int				csize;
	void			*page;
	void			*next;
}					t_small;

typedef struct		s_large
{
	void			*page;
	void			*next;
}					t_large;

typedef struct		s_page
{
	t_tiny			*tiny_head;
	t_small			*small_head;
	t_large			*large_head;
	int				nb_tiny;
}					t_page;

extern t_page		g_page;

int					print_t(void);
int					print_s(void);
int					print_l(void);
void				free(void *ptr);
void				ft_free(void *ptr);
void				print_bytes(const void *ptr, size_t size);
void				*malloc(size_t size);
void				*set_header(void *page, size_t size);
void				*realloc(void *ptr, size_t size);
void				*ft_malloc(size_t size);
void				*get_mem(size_t size);
t_tiny				*ft_new_tiny(void);
t_small				*ft_new_small(size_t size);
t_large				*ft_new_large(size_t size);
t_tiny				*ft_tiny_find(t_tiny *tiny_head, int nbtiny);
t_small				*ft_small_find(t_small *small_head);
t_large				*ft_large_find(t_large *large_head);
size_t				tiny_size(void);
size_t				small_size(void);
size_t				get_page_size(size_t size);
void				ft_nope(void);
void				ft_atoi_hex(void *ptr);
void				ft_atoi_hex_nl(void *ptr);

#endif
