/*
** libtekgui.h for  in /home/descho_e/year_2015_2016/I_graph/gfx_tekgui
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Feb  2 13:19:12 2016 Eric DESCHODT
** Last update Sun Mar 27 16:07:29 2016 Eric DESCHODT
*/

#ifndef			IGRAPH_H_
# define		IGRAPH_H_

# include <unistd.h>
# include "lapin.h"
# include "libgraph.h"
# include "op.h"
# include "corewar.h"

typedef struct s_button
{
  t_bunny_pixelarray    *options;
  t_bunny_pixelarray    *options_select;
  t_bunny_pixelarray    *fight;
  t_bunny_pixelarray    *fight_select;
  t_bunny_pixelarray    *credits;
  t_bunny_pixelarray    *credits_select;
  t_bunny_pixelarray    *wesh;
  t_bunny_pixelarray    *wesh_select;
  t_bunny_pixelarray    *back;
  t_bunny_pixelarray    *back_select;
  t_bunny_pixelarray    *minus;
  t_bunny_pixelarray    *minus_select;
  t_bunny_pixelarray    *plus;
  t_bunny_pixelarray    *plus_select;
}			t_button;

typedef struct          s_font
{
  t_texture             *font;
  t_bunny_position      letters[127];
  int                   size;
}                       t_font;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_texture		*back;
  t_texture		*logo;
  t_texture		*ko;
  t_bunny_position	size;
  t_bunny_position	pos;
  t_bunny_effect	*sko;
  t_bunny_effect	*eko;
  t_font		font;
  t_bunny_music		*music;
  t_texture		*end;
  t_texture		*youwin;
  t_texture		*chara_select;
  int			select;
  t_bunny_pixelarray    *mouse;
  t_bunny_pixelarray    *background;
  t_bunny_pixelarray    *menu_screen;
  t_bunny_pixelarray    *credits_screen;
  t_bunny_pixelarray    *options_screen;
  t_bunny_pixelarray    *wesh_screen;
  t_bunny_pixelarray    *volume;
  t_bunny_pixelarray    *effects;
  t_bunny_music         *wesh_sound;
  t_bunny_music         *click_sound;
  t_bunny_music         *fight_sound;
  t_button              *button;
  t_color               fade;
  int                   click;
  int                   page;
  int                   display_mouse;
  int                   vol_music;
  int                   vol_effect;

}			t_data;

t_bunny_response        mainloop(void *_data);

t_bunny_response        endloop(void *_data);

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym      key,
			    void                *p);

void                    square(t_bunny_pixelarray *pix,
                               t_bunny_position size,
                               t_bunny_position pos,
                               int champ);

void                    printboardgraph(t_bunny_pixelarray *pix,
                                        unsigned char board[2][MEM_SIZE]);

void                    printboardgraph2(t_bunny_pixelarray *pix,
					 unsigned char board[2][MEM_SIZE]);

int                     load_font(t_font *font,
                                  char *name,
                                  int size);

void                    my_tekletter(char c,
                                     t_bunny_pixelarray *pix,
                                     t_font font,
                                     t_bunny_position *pos);


void                    my_tektext(char *str,
                                   t_bunny_pixelarray *pix,
                                   t_font font,
                                   t_bunny_position *start);

void                    put_nbr_scr(int nb, t_data *data);

int			free_texture(t_texture *text);

int                     menu(t_data *data);

t_bunny_response        pausing(void *_data);

void                    tekblit(t_bunny_pixelarray              *destination,
                                const t_bunny_pixelarray        *origin,
                                const t_bunny_position          *pos);

# endif /* IGRAPH_H_ */

