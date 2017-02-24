/*
** image.c for image_load  in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 19 20:54:30 2016 Léo Hubert
** Last update Tue Jan 26 21:34:40 2016 Léo Hubert
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void			load_bitmap_bis(t_image	           *header,
					t_bunny_position   pos,
					char		   *buffer,
					t_bunny_pixelarray *pix)
{
  t_color		color;
  int			i;

  i = header->pos_pix;
  pos.x = 0;
  pos.y = header->height - 1;
   while (pos.y >= 0)
    {
      while ((unsigned int)pos.x < header->width)
  	{
  	  color.argb[2] = buffer[++i];
  	  color.argb[1] = buffer[++i];
  	  color.argb[0] = buffer[++i];
  	  color.argb[3] = buffer[++i];
	  tekpixel(pix, &pos, &color);
  	  pos.x++;
  	}
      pos.x = 0;
      pos.y--;
    }
   bunny_free(buffer);
}

t_bunny_pixelarray	*load_bitmap(const char	*file)
{
  t_bunny_pixelarray	*pix;
  char			*buffer;
  t_image		header;
  int			fd;
  t_bunny_position	pos;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((read(fd, &header, 54)) == -1)
    return (NULL);
  close(fd);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((pix = bunny_new_pixelarray(header.width, header.height)) == NULL)
    return (NULL);
  if ((buffer = bunny_malloc(sizeof(char) *
			     (header.width * header.height * 4))) == NULL)
    return (NULL);
  if ((read(fd, buffer, header.size_octe)) == -1)
    return (NULL);
  load_bitmap_bis(&header, pos, buffer, pix);
  if ((close(fd)) == -1)
    return (NULL);
  return (pix);
}
