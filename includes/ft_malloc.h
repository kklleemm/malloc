/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:41:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 14:13:40 by cdeniau          ###   ########.fr       */
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
# define TINY_PAGE 102400  // min 200 TINY
# define SMALL 4096
# define SMALL_PAGE 409600  // min 100 SMALL

typedef struct		s_tiny
{
	void			**firstblock;
	void			*next;
	int				size;
}					t_tiny;

typedef struct		s_small
{
	void			**firstblock;
	void			*next;
	int				size;
}					t_small;

typedef struct		s_large
{
	void			*page;
	void			*next;
}					t_large; // t large gro

typedef struct		s_page
{
	t_tiny			*tiny_head;
	t_small			*small_head;
	t_large			*large_head;
	int				nb_tiny;
	int				nb_small;
	int				nb_large;
	int				print;
}					t_page;

extern t_page		g_page;

void				ft_print(void);
void				free(void *ptr);
void				ft_free(void *ptr);
void				print_bytes(const void *ptr, size_t size);
void				*malloc(size_t size);
void				*set_header(void **firstblock, size_t size);
void				*realloc(void *ptr, size_t size);
void				*ft_malloc(size_t size);
void				*ft_malloc_tiny(size_t size);
void				*ft_malloc_small(size_t size);
void				*get_mem(size_t size);
t_tiny				*ft_new_tiny(void);
t_small				*ft_new_small(void);
t_large				*ft_new_large(size_t size);
t_tiny				*ft_tiny_find(t_tiny *tiny_head, int nbtiny);
t_small				*ft_small_find(t_small *small_head, int nbsmall);
t_large				*ft_large_find(t_large *large_head, int nblarge);
size_t				tiny_size(void);
size_t				small_size(void);
size_t				get_page_size(size_t size);
void				ft_nope(void);
void				ft_atoi_hex(void *ptr);
void				ft_atoi_hex_nl(void *ptr);
int					get_mem_size(void **firstblock);

#endif
