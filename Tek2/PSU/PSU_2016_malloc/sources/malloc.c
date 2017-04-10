/*
** malloc.c for PSU_2016_malloc in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_malloc/sources
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Mon Jan 30 18:36:24 2017 Leo HUBERT
** Last update Fri Feb 10 14:02:35 2017 Leo HUBERT
*/

#include "malloc.h"

void		*malloc(size_t size)
{
  t_chunk	*tmp;
  t_chunk	*last;

  pthread_mutex_lock(&g_thread);
  if (g_base)
  {
    last = g_base;
    if ((tmp = find_chunk(&last, size)))
    {
      if ((tmp->size - size) >= (CHUNK_SIZE + tmp->size))
        split_chunk(tmp, size);
      tmp->free = 0;
    }
    else
      if (!(tmp = extend_heap(last, size)))
        return (NULL);
  }
  else
    {
      if (!(tmp = extend_heap(NULL, size)))
	return (NULL);
      g_base = tmp;
    }
  pthread_mutex_unlock(&g_thread);
  return (tmp->ptr);
}

void		*calloc(size_t number, size_t size)
{
  size_t	total;
  void		*new;

  total = number * size;
  new = malloc(total);
  if (new)
    memset(new, 0, total);
  return (new);
}

void		free(void *ptr)
{
  t_chunk	*tmp;

  pthread_mutex_lock(&g_thread);
  if (ptr)
  {
    tmp = get_chunk(ptr);
    if (!tmp)
      return;
    tmp->free = 1;
    if (tmp->prev && tmp->prev->free)
      tmp = fusion(tmp->prev);
    if (tmp->next)
      tmp = fusion(tmp);
    else
    {
      if (tmp->prev)
        tmp->prev->next = NULL;
      else
        g_base = NULL;
      brk(tmp);
    }
  }
  pthread_mutex_unlock(&g_thread);
}

void		*realloc(void *ptr, size_t size)
{
  void		*buff;
  t_chunk	*tmp;

  if (!ptr)
    return (malloc(size));
  tmp = get_chunk(ptr);
  if (tmp && tmp->size && tmp->size >= size)
    return (ptr);
  buff = malloc(size);
  if (buff)
    {
      memcpy(buff, ptr, tmp->size);
      free(ptr);
    }
  return (buff);
}
