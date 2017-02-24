/*
** linked_list.c for linked_list in /home/hubert_i/rendu/PSU_2015_my_select
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Dec  8 13:44:18 2015 leo hubert
** Last update Wed Apr  6 23:30:39 2016 Léo Hubert
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

t_env		*add_env(t_env *env, char *str, char *key)
{
  t_env		*newelem;

  if ((newelem = malloc(sizeof(t_env))) == NULL)
    return (NULL);
  newelem->str = str;
  newelem->key = key;
  newelem->first = 0;
  newelem->next = NULL;
  newelem->prev = NULL;
  if (env == NULL)
    {
      newelem->first = 1;
      newelem->next = newelem;
      newelem->prev = newelem;
    }
  else
    {
      while (env->first != 1)
	env = env->next;
      newelem->prev = env->prev;
      newelem->next = env;
      env->prev->next = newelem;
      env->prev = newelem;
    }
  return (newelem);
}

int	show_env(t_env *env)
{
  while (env->first != 1)
    env = env->next;
  my_putstr(env->key);
  my_putchar('=');
  my_putstr(env->str);
  env = env->next;
  while (env->first != 1)
    {
      my_putstr(env->key);
      my_putchar('=');
      my_putstr(env->str);
      my_putchar('\n');
      env = env->next;
    }
  return (0);
}

t_env		*delete_maillon(t_env *env)
{
  t_env		*maillon;

  maillon = env;
  env = env->next;
  if (env->prev->first == 1)
    env->first = 1;
  env->prev->prev->next = env->prev->next;
  env->prev = env->prev->prev;
  free(maillon);
  return (env);
}
