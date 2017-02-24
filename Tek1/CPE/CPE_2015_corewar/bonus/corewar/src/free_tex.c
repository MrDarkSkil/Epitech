/*
** free_tex.c for  in /home/descho_e/year_2015_2016/I_graph/gfx_scroller
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sun Mar 20 04:56:47 2016 Eric DESCHODT
** Last update Sun Mar 27 01:01:16 2016 Eric DESCHODT
*/

#include "corewar.h"

int             free_texture(t_texture *text)
{
  int           i;

  if (text == NULL)
    return (-1);
  i = 0;
  while (i < text->height)
    {
      if (text->color[i] != NULL)
        bunny_free(text->color[i]);
      i++;
    }
  if (text->color != NULL)
    bunny_free(text->color);
  bunny_free(text);
  return (1);
}
