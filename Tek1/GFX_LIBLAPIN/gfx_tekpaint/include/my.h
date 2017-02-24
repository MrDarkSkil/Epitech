/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Fri May 27 18:41:36 2016 Jabbari Yassir
*/

#ifndef MY_
#define MY_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
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
  short int			magic_number;
  unsigned int			size;
  unsigned int			inutile;
  unsigned int			pos_pix;
  unsigned int			size_header;
  unsigned int			width;
  unsigned int			height;
  short int			plan_bit;
  short int			plan_bitbis;
  unsigned int			compression;
  unsigned int			size_octe;
  unsigned int			width_metre;
  unsigned int			height_metre;
  unsigned int			number_colorpal;
  unsigned int			number_color;
} __attribute__ ((packed))	t_image;

typedef	struct	s_line
{
  int	dx;
  int	dy;
  int	xinc;
  int	yinc;
  int	cumul;
  int	x;
  int	y;
}	t_line;

typedef struct s_list
{
  int			x;
  int			y;
  int			d;
  t_bunny_position	pos2;
}	t_list;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*menu_1;
  t_bunny_pixelarray	*menu_2;
  t_bunny_position	pos;
  t_bunny_position	pos_old;
  t_bunny_effect	*bouton;
  t_bunny_music		*music;
  int			music_play;
  int			height;
  int			width;
  int			click;
  t_color		color;
  int			in_tab;
  char			type;
  char			pencil;
  int			size;
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
void			left(t_data *data);
void			right(t_data *data);
void			up(t_data *data);
void			down(t_data *data);
t_bunny_response	mouse(t_bunny_position	*relativ,
			      void		*my_data);
t_bunny_pixelarray	*load_bitmap(const char	*file);
void			circle(t_data *data);
void			square(t_data *data);
void			paint(t_data *data);
void			erase(t_data *data);
void			ligne(t_data *data);
void			pen(t_data *data);
void			draw(t_data *data);
void			set_max_heap_size(size_t);
void			bouton_handler(t_data *data);
void			check_next(t_color	    color,
				   t_bunny_position pos,
				   t_data	    *data);
void                    bouton_check(t_data *data);
void			refresh_header(t_data *data);
void			menu(t_data *data);
void			tekcircle_bis(t_bunny_pixelarray	*pix,
				      t_bunny_position	*pos,
				      t_color		*color,
				      t_list		list);
void			teksquare(t_bunny_pixelarray	*pix,
				  t_bunny_position	*pos,
				  t_color		*color,
				  int			r);
void		       	tekcircle(t_bunny_pixelarray	*pix,
				  t_bunny_position	*pos,
				  t_color		*color,
				  int			r);
void			bouton_click(t_data *data,
				     t_bunny_keysym key);
void			bouton_sound(t_data *data);
void			play_music(t_data *data);

#endif
