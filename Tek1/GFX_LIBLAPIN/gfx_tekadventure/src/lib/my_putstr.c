/*
** my_putstr.c for my_putstr in /home/hubert_i/gfx_tekadventure
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Apr 17 17:19:42 2016 Léo Hubert
** Last update Sun Apr 17 17:21:57 2016 Léo Hubert
*/

# include		"tekAdventure.h"

void			my_putchar(char c)
{
  write(1, &c, 1);
}

int			my_putstr(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
