/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:41:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/23 16:34:16 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "../libft/libft.h"

# define FLAGS PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON
# define FLAGS2 PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON
# define TINY 512
# define TINY_PAGE 102400
# define SMALL 4096
# define SMALL_PAGE 409600

typedef struct		s_header
{
	void			*next;
	size_t			size;
	int				flg;
}					t_header;

typedef struct		s_tiny
{
	t_header		*firstblock;
	void			*next;
	size_t			totalsize;
}					t_tiny;

typedef struct		s_small
{
	t_header		*firstblock;
	void			*next;
	size_t			totalsize;
}					t_small;

typedef struct		s_large
{
	void			*page;
	void			*next;
	size_t			size;
}					t_large;

typedef struct		s_page
{
	t_tiny			*tiny_head;
	t_small			*small_head;
	t_large			*large_head;
	int				print;
}					t_page;

extern t_page		g_page;
pthread_mutex_t		g_lock;

void				free(void *ptr);
void				print_mem(void *mem);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				*calloc(size_t count, size_t size);
void				*set_header(void *firstblock, size_t size);
void				*realloc(void *ptr, size_t size);
void				*malloc(size_t size);
void				*ft_malloc_tiny(size_t size);
void				*find_ptr_t(t_header *header);
void				*ft_malloc_small(size_t size);
void				*find_ptr_s(t_header *header);
void				*ft_malloc_large(size_t size);
t_tiny				*ft_new_tiny(void);
t_small				*ft_new_small(void);
t_large				*ft_new_large(size_t size);
void				*ft_overninethousand(void);
t_tiny				*ft_tiny_find(t_tiny *tiny_head);
t_small				*ft_small_find(t_small *small_head);
t_large				*ft_large_find(t_large *large_head);
void				ft_print_tiny(void);
void				ft_print_small(void);
void				ft_print_large(void);
void				show_alloc_mem();
size_t				tiny_size(void);
size_t				small_size(void);
void				ft_nope(void);
void				ft_atoi_hex(void *ptr);
void				ft_atoi_hex_nl(void *ptr);
int					check_empty_page_t(t_tiny *page);
int					check_empty_page_s(t_small *page);
int					modif_mem_size(void **firstblock, int size);
size_t				mulpagesize(size_t size);

#endif
