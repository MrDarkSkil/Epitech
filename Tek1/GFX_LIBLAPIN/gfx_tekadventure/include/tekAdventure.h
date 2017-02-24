/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Sun Apr 17 18:52:11 2016 Loic Lopez
*/

#ifndef MY_
# define MY_

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <time.h>
# include "lapin.h"
# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN    "\x1b[36m"
# define COLOR_RESET   "\x1b[0m"
# define LINE		((line.dx > line.dy) ? (line.dx) : (line.dy))
# define ULINE		((line.dx > line.dy) ? (line.dy) : (line.dx))
# define SINC		((line.dx > line.dy) ? (line.yinc) : (line.xinc))
# define USINC		((line.dx > line.dy) ? (line.xinc) : (line.yinc))
# define XY		((line.dx > line.dy) ? (pos[0].x += line.xinc) : XYO)
# define YX		((line.dx > line.dy) ? (pos[0].y += line.yinc) : YXO)
# define XYO		(pos[0].y += line.yinc)
# define YXO		(pos[0].x += line.xinc)
# define ABS(value)      ((value < 0) ? (-value) : (value))

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

typedef struct s_spritePos
{
  t_bunny_position	pos;
  int			first;
  struct s_spritePos	*next;
  struct s_spritePos	*prev;
}		t_spritePos;

typedef struct s_sprite
{
  t_bunny_pixelarray	*pix;
  int			size[2];
  t_bunny_position	pos;
  t_spritePos		*spritePos;
}	t_sprite;

typedef struct s_sprites
{
  t_sprite		*loading;
}	t_sprites;

typedef struct s_sounds
{
  t_bunny_music		*ambiance;
}		t_sounds;

typedef struct s_textures
{
  t_bunny_pixelarray	*middleScene1_light;
  t_bunny_pixelarray	*middleScene1_dark;
  t_bunny_pixelarray	*middleScene2_light;
  t_bunny_pixelarray	*middleScene2_dark;
  t_bunny_pixelarray	*middleScene3;
  t_bunny_pixelarray	*sky;
  t_bunny_pixelarray	*nextRight;
  t_bunny_pixelarray	*nextLeft;
  t_bunny_pixelarray	*nextDown;
  t_bunny_pixelarray	*menu;
  t_bunny_pixelarray	*feuille1;
  t_bunny_pixelarray	*feuille2;
}		t_textures;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_sprites		*sprites;
  t_sounds		*sounds;
  t_textures		*textures;
  t_bunny_position	pos;
  t_bunny_position      view;
  t_bunny_ini		*iniSprites;
  t_bunny_ini		*iniSounds;
  int			showAffiche1;
  int			showAffiche2;
  int			click;
  int			max_ram;
  int			state;
  int			light;
  int			key;
}	t_data;

void			tekpixel(t_bunny_pixelarray		*pix,
				 t_bunny_position		*pos,
				 t_color			*color);
void			tekline(t_bunny_pixelarray		*pix,
				t_bunny_position		*pos,
				t_color				*color);
void			tekpaint(t_bunny_pixelarray		*pix,
				 t_color			*color);
t_color			getpixel(t_bunny_pixelarray		*pix,
				 t_bunny_position		*pos);
int			my_strlen(char				*str);
void			tektext(t_bunny_pixelarray		*pix,
				t_bunny_pixelarray		*font,
				t_bunny_position		*pos,
				char				*str);
void			tekchar(t_bunny_pixelarray		*pix,
				t_bunny_pixelarray		*font,
				t_bunny_position		*pos,
				t_tektext			*tek);
void			tekblit(t_bunny_pixelarray		*destination,
				const t_bunny_pixelarray	*origin,
				const t_bunny_position		*pos);
void			tekcircle_bis(t_bunny_pixelarray	*pix,
				      t_bunny_position		*pos,
				      t_color			*color,
				      t_list			list);
void			teksquare(t_bunny_pixelarray		*pix,
				  t_bunny_position		*pos,
				  t_color			*color,
				  int				r);
void		       	tekcircle(t_bunny_pixelarray		*pix,
				  t_bunny_position		*pos,
				  t_color			*color,
				  int				r);
int			my_getnbr(char				*nbr);
t_sprite		*loadSprite(char *sprite, t_bunny_ini *sprites, t_sprite *newSprite);
int			loadSprites(t_data *data);
t_spritePos		*add_spritePos(t_spritePos		*list,
				       int			y,
				       int			x);
t_bunny_response		scene1(void *my_data);
t_bunny_response		scene2(void *my_data);
t_bunny_response		scene3(void *my_data);
void				showNext1(t_data	*data,
					  int		y,
					  int		x);
void				showNext2(t_data	*data,
					  int		y,
					  int		x);
void				showNext3(t_data	*data,
					  int		y,
					  int		x);
void				showNext4(t_data	*data,
					  int		y,
					  int		x);
void				showAffiche1(t_data    	*data,
					     int       	y,
					     int	x);
void				showAffiche2(t_data    	*data,
					     int       	y,
					     int	x);
t_bunny_response		menu(void *my_data);
void				tekResize(t_bunny_pixelarray		*destination,
					  const t_bunny_pixelarray	*origin,
					  const t_bunny_position	*start,
					  int				size[2]);
t_bunny_response		loadingScreen(void *my_data);
int				initTekadventure(t_data *data);
int				loadConfig(t_data *data);
t_bunny_response		mouse(t_bunny_position	*relativ,
				      void		*my_data);
t_bunny_response		click(t_bunny_event_state            state,
				      t_bunny_mousebutton            button,
				      void                           *my_data);
int				loadMusic(t_data *data);
int				loadTextures(t_data *data);
int				my_putstr(char *str);

t_bunny_response		key(t_bunny_event_state	state,
				    t_bunny_keysym	key,
				    void		*my_data);

void				showNext1(t_data		*data,
					  int			y,
					  int			x);

void				showNext2(t_data		*data,
					  int			y,
					  int			x);


void				showNext3(t_data		*data,
					  int			y,
					  int			x);

void				showNext4(t_data		*data,
					  int			y,
					  int			x);

void				showAffiche2(t_data    		*data,
					     int       		y,
					     int		x);

void				showAffiche1(t_data    		*data,
					     int       		y,
					     int		x);

t_bunny_response		loadingScreen(void *my_data);

int				loadConfig(t_data *data);

int				initTekadventure(t_data *data);

t_bunny_response		menu(void *my_data);

t_bunny_response		mouse(t_bunny_position	*relativ,
				      void		*my_data);

t_bunny_response		click(t_bunny_event_state            state,
				      t_bunny_mousebutton            button,
				      void			     *my_data);

int				check_scene3(t_data *data, t_bunny_position init,
					     int size[2]);

void				print_scene1(t_data *data, t_bunny_position init,
					     int size[2]);



#endif
