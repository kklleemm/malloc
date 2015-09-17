/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:41:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/17 17:26:44 by cdeniau          ###   ########.fr       */
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

typedef struct		s_page
{
	void			*firstblock;
	void			*next;
	int				full;
	char			type;
	size_t			totalsize;
}					t_page;

typedef struct		s_env
{
	t_page			*page;
	int				print;
}					t_env;

extern t_env		g_env;

void				free(void *ptr);
void				print_mem(void *mem);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
char				get_type(size_t size);
void				*calloc(size_t count, size_t size);
void				*set_header(void *firstblock, size_t size, int first);
void				*realloc(void *ptr, size_t size);
void				*malloc(size_t size);
//void				*ft_malloc_large(size_t size);
//t_large				*ft_new_large(size_t size);
void				*ft_overninethousand(void);
void				ft_new_malloc(t_page *page, size_t size);
void				ft_print_tiny(void);
void				ft_print_small(void);
//void				ft_print_large(void);
void				show_alloc_mem();
void				ft_nope(void);
void				ft_atoi_hex(void *ptr);
void				ft_atoi_hex_nl(void *ptr);
int					modif_mem_size(void **firstblock, int size);
int					mulpagesize(int size);
size_t				get_page_size(size_t size);

#endif
