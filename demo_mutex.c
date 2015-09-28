/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 04:17:13 by gallard           #+#    #+#             */
/*   Updated: 2015/07/20 04:41:50 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

	static void *
thread_func(void *ignored_argument)
{
	int s;
	s = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	if (s != 0)
		handle_error_en(s, "pthread_setcancelstate");
	printf("thread_func(): started; cancellation disabled\n");
	

	printf("thread_func(): about to enable cancellation\n");
	s = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if (s != 0)
		handle_error_en(s, "pthread_setcancelstate");

	char	*p;
	size_t	i = 0;
	while (i < 10000)
	{
		p = malloc(128);
		if (p)
			p[0] = 42;
		i++;
	}

	printf("thread_func(): not canceled!\n");
	return NULL;
}

	int
main(void)
{
	pthread_t thr;
	void *res;
	int s;

	s = pthread_create(&thr, NULL, &thread_func, NULL);
	if (s != 0)
		handle_error_en(s, "pthread_create");

	char	*p;
	size_t	i = 1000;

	p = 0;
	while (i < 4000)
	{
		p = realloc(p, i);
		if (p)
			p[0] = 42;
		else
		{
			puts("no");
			exit(1);
		}
		i++;
	}

	printf("main(): sending cancellation request\n");
	s = pthread_cancel(thr);
	if (s != 0)
		handle_error_en(s, "pthread_cancel");
	s = pthread_join(thr, &res);
	if (s != 0)
		handle_error_en(s, "pthread_join");
	if (res == PTHREAD_CANCELED)
		printf("main(): thread was canceled\n");
	else
		printf("main(): thread wasn't canceled (shouldn't happen!)\n");
	show_alloc_mem();
	exit(EXIT_SUCCESS);
}
