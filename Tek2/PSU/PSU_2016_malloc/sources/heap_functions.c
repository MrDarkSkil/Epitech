/*
** heap_functions.c for PSU_2016_malloc in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_malloc/sources
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Fri Feb 03 12:23:22 2017 Leo HUBERT
** Last update	Fri Feb 10 14:16:45 2017 Full Name
*/

#include "malloc.h"

t_chunk		*get_chunk(void *ptr)
{
  char		*tmp;
  tmp = ptr;
  return (ptr = tmp -= CHUNK_SIZE);
}

t_chunk		*find_chunk(t_chunk **last, size_t size)
{
  t_chunk	*tmp;

  tmp = *last;
  while (tmp && (!(tmp->free && tmp->size >= size)))
  {
    *last = tmp;
    tmp = tmp->next;
  }
  return (tmp);
}

t_chunk		*extend_heap(t_chunk *last, size_t size)
{
  t_chunk	*tmp;

  tmp = sbrk(0);
  if (sbrk(sizeof(t_chunk) + size) == (void*)-1)
    return (NULL);
  tmp->size = size;
  tmp->next = NULL;
  tmp->prev = NULL;
  if (last)
  {
    last->next = tmp;
    tmp->prev = last;
  }
  tmp->free = 0;
  tmp->ptr = tmp->data;
  return (tmp);
}

void		split_chunk(t_chunk *src, size_t size)
{
  t_chunk	*new;

  new = src->ptr + size;
  new->size = src->size - size - CHUNK_SIZE;
  new->next = src->next;
  new->prev = src;
  new->free = 1;
  src->size = size;
  src->next = new;
}

t_chunk		*fusion(t_chunk *src)
{
  if (src->next && src->next->free)
  {
    src->size += CHUNK_SIZE + src->next->size;
    src->next = src->next->next;
    if (src->next)
      src->next->prev = src;
  }
  return (src);
}
