/*
** malloc.h for PSU_2016_malloc in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_malloc/include
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Thu Feb 02 23:45:04 2017 Leo HUBERT
** Last update Fri Feb 10 14:03:04 2017 Leo HUBERT
*/

#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

typedef struct		s_chunk
{
  size_t		size;
  struct s_chunk	*next;
  struct s_chunk	*prev;
  int			free;
  void			*ptr;
  char			data[1];
}			t_chunk;

#define CHUNK_SIZE sizeof(t_chunk) - 8

void			*g_base;
pthread_mutex_t		g_thread;


t_chunk			*get_chunk(void *ptr);
t_chunk			*find_chunk(t_chunk **last, size_t size);
t_chunk			*extend_heap(t_chunk *last, size_t size);
void			split_chunk(t_chunk *src, size_t size);
void			*malloc(size_t size);
void			*calloc(size_t number, size_t size);
t_chunk			*fusion(t_chunk *src);
void			free(void *ptr);
void			*realloc(void *ptr, size_t size);
int			my_putchar(char c);
int			my_strlen(char *str);
int			my_putstr(char *str);
int			my_putnbr_g_base(int nbr, char *g_base);
void			show_alloc_mem();

#endif /* !MY_MALLOC_H */
