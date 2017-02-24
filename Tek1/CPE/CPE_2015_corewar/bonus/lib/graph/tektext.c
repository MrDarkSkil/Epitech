/*
** tektext.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/CPE_2015_corewar/bonus
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sat Mar 26 14:55:41 2016 Eric DESCHODT
** Last update Sat Mar 26 23:54:16 2016 Eric DESCHODT
*/

#include "corewar.h"

int                     load_font(t_font *font,
                                  char *name,
                                  int size)
{
  int                   c;
  int                   mov;

  font->font = load_bitmap(name);
  c = 'a' - 1;
  mov = 0;
  while (++c <= 'z')
    {
      font->letters[c].x = mov;
      font->letters[c].y = 0;
      mov += 9;
    }
  c = 'A' - 1;
  while (++c <= 'Z')
    {
      font->letters[c].x = mov;
      font->letters[c].y = 0;
      mov += 9;
    }
  font->size = size;
  c = '1' - 1;
  mov = 0;
  while (++c <= '9')
    {
      font->letters[c].x = mov;
      font->letters[c].y = 10;
      mov += 9;
    }
  font->letters['0'].x = mov;
  font->letters['0'].y = 10;
  return (0);
}

void                    my_tekletter(char c,
                                     t_bunny_pixelarray *pix,
                                     t_font font,
                                     t_bunny_position *pos)
{
  t_bunny_position      pixel;
  t_bunny_position      draw;
  t_color               color;
  t_bunny_position      wr;

  draw.x = font.letters[(int)c].x;
  draw.y = font.letters[(int)c].y;
  pixel.y = -1;
  while (++pixel.y < 11 * font.size)
    {
      pixel.x = -1;
      while (++pixel.x < 8 * font.size)
        {
          color = font.font->color[draw.y + pixel.y / font.size]
            [draw.x + pixel.x / font.size];
          wr.x = pos->x + pixel.x;
          wr.y = pos->y + pixel.y;
          if (color.argb[0] > 150 && color.argb[3] == 255)
            tekpixel(pix, &wr, &color);
        }
    }
  pos->x += (8 + 1) * font.size;
}

void                    my_tektext(char *str,
                                   t_bunny_pixelarray *pix,
                                   t_font font,
                                   t_bunny_position *start)
{
  int                   i;
  t_bunny_position      pos;

  if (font.font == NULL)
    return;
  pos.x = start->x;
  pos.y = start->y;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '.')
        pos.x += (6 + 1) * font.size;
      else
        my_tekletter(str[i], pix, font, &pos);
      i++;
    }
}
