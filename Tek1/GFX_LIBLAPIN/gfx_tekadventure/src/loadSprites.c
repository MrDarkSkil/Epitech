/*
** load_sprites.c for load_sprites in /home/hubert_i/rendu/2015/INFO/gfx_tekadventure
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Apr 14 18:13:13 2016 Léo Hubert
** Last update Sun Apr 17 18:15:19 2016 Loic Lopez
*/

# include		"tekAdventure.h"

t_sprite		*init_sprites(t_sprite *newSprite, char *sprite,
				      t_bunny_ini *sprites)
{
  char			*result;

 newSprite->spritePos = NULL;
  if ((result = (char *)bunny_ini_get_field(sprites,
					    sprite, "image", 0)) == NULL)
    return (NULL);
  if ((newSprite->pix = bunny_load_pixelarray(result)) == NULL)
    return (NULL);
  if ((newSprite->size[0] = my_getnbr((char *)bunny_ini_get_field(sprites,
								 sprite, "height", 0))) == -1 ||
      (newSprite->size[1] = my_getnbr((char *)bunny_ini_get_field(sprites,
								 sprite, "width", 0))) == -1)
    return (NULL);
  newSprite->pos.x = 0;
  newSprite->pos.y = 0;
  return (newSprite);
}

t_sprite		*loadSprite(char *sprite, t_bunny_ini *sprites,
				    t_sprite *newSprite)
{
  char			*result;
  int			i;
  int			x;
  int			y;

  if ((newSprite = bunny_malloc(sizeof(t_sprite))) == NULL)
    return (NULL);
  i = 0;
  if ((newSprite = init_sprites(newSprite, sprite, sprites)) == NULL)
    return (NULL);
  while ((result = (char *)bunny_ini_get_field(sprites,
					       sprite, "pos", i)) != NULL)
    {
      if ((y = my_getnbr(result)) == -1)
	return (NULL);
      i++;
      if ((result = (char *)bunny_ini_get_field(sprites,
						sprite, "pos", i)) == NULL
	  || (x = my_getnbr(result)) == -1)
	return (NULL);
      newSprite->spritePos = add_spritePos(newSprite->spritePos, y, x);
      i++;
    }
  return (newSprite);
}
