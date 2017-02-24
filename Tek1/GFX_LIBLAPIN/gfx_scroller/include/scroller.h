/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Sun Mar 20 20:11:13 2016 Léo Hubert
*/

#ifndef MY_
#define MY_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "lapin.h"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"
#define	LINE		((line.dx > line.dy) ? (line.dx) : (line.dy))
#define	ULINE		((line.dx > line.dy) ? (line.dy) : (line.dx))
#define	SINC		((line.dx > line.dy) ? (line.yinc) : (line.xinc))
#define	USINC		((line.dx > line.dy) ? (line.xinc) : (line.yinc))
#define XY		((line.dx > line.dy) ? (pos[0].x += line.xinc) : (pos[0].y += line.yinc))
#define YX		((line.dx > line.dy) ? (pos[0].y += line.yinc) : (pos[0].x += line.xinc))
#define ABS(value)      ((value < 0) ? (-value) : (value))

typedef struct s_image
{
  short int		magic_number;
  unsigned int		size;
  unsigned int		inutile;
  unsigned int		pos_pix;
  unsigned int		size_header;
  unsigned int		width;
  unsigned int		height;
  short int		plan_bit;
  short int		plan_bitbis;
  unsigned int		compression;
  unsigned int		size_octe;
  unsigned int		width_metre;
  unsigned int		height_metre;
  unsigned int		number_colorpal;
  unsigned int		number_color;
} __attribute__ ((packed))	t_image;

typedef	struct	s_line
{
  int			dx;
  int			dy;
  int			xinc;
  int			yinc;
  int			cumul;
  int			x;
  int			y;
}	t_line;

typedef struct s_list
{
  int			x;
  int			y;
  int			d;
  t_bunny_position	pos2;
}	t_list;

typedef struct s_tektext
{
  t_bunny_position	save_pos;
  t_bunny_position	save_caract;
  t_bunny_position	caract;
  t_color		color;
  int			i;
  int			l;
  int			c;
  char			*ordre;
}	t_tektext;

typedef struct s_textures
{
  t_bunny_pixelarray	*sol;
  t_bunny_pixelarray	*nuit;
  t_bunny_pixelarray	*font;
}	t_textures;

typedef struct s_sounds
{
  t_bunny_effect	*music;
  t_bunny_ini		*sample;
  int			duration;
  int			i;
}	t_sounds;

typedef struct s_sprite
{
  t_bunny_pixelarray	*sprite;
  t_bunny_position	*pos;
  int			first;
  struct s_sprite	*next;
  struct s_sprite	*prev;
}	t_sprite;

typedef struct s_sprites
{
  t_sprite		*cloud;
  t_sprite		*zombieBorn;
  t_sprite		*zombieWalk;
}	t_sprites;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_textures		*textures;
  t_sprites		*sprites;
  t_sounds		*sounds;
  t_bunny_position	pos;
  int			click;
}	t_data;

void			tekpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos,
				 t_color		*color);
void			tekline(t_bunny_pixelarray	*pix,
				t_bunny_position	*pos,
				t_color			*color);
void			tekpaint(t_bunny_pixelarray	*pix,
				 t_color		*color);
t_color			getpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos);
int	malloc_textures(t_data *data);
int			load_cloud(t_data *data);
int	load_sprites(t_data *data);
int	load_textures(t_data *data);
t_bunny_pixelarray	*scale_pix(t_bunny_pixelarray	*pix,
				   int			posx,
				   int			posy,
				   int			size);
int		load_bornzombie(t_data *data);
int		load_zombieWalk(t_data *data);
int	my_strlen(char *str);
void			tektext(t_bunny_pixelarray	*pix,
				t_bunny_pixelarray	*font,
				t_bunny_position	*pos,
				char			*str);
void		tekchar(t_bunny_pixelarray	*pix,
			t_bunny_pixelarray	*font,
			t_bunny_position	*pos,
			t_tektext		*tek);
void			tekblit(t_bunny_pixelarray		*destination,
				const t_bunny_pixelarray	*origin,
				const t_bunny_position		*pos);
void	tekcircle_bis(t_bunny_pixelarray	*pix,
		      t_bunny_position	*pos,
		      t_color		*color,
		      t_list		list);
void			teksquare(t_bunny_pixelarray	*pix,
				  t_bunny_position	*pos,
				  t_color		*color,
				  int			r);
void	       	tekcircle(t_bunny_pixelarray	*pix,
			  t_bunny_position	*pos,
			  t_color		*color,
			  int			r);
int	load_music(t_data *data);
void		play_music(t_data *data);
void			display_grass(t_data *data);
void			display_font(t_data *data);
void			display_message(t_data *data);
void			display_map(t_data *data);
void	display_zombieWalk(t_data *data);
void	display_zombieBorn(t_data *data);
void			display_cloud(t_data *data);
t_sprite	*add_sprite(t_sprite		*list,
			    t_bunny_pixelarray	*new_sprite,
			    t_bunny_position	*pos);
#endif
