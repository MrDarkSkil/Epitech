/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Sun Mar 27 17:58:35 2016 Léo Hubert
*/

#ifndef GRAPH__
# define GRAPH_

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <time.h>
# include "corewar.h"
# include "igraph.h"
# include "lapin.h"

t_bunny_response	key2(t_bunny_event_state	state,
			     t_bunny_keysym	key,
			     void		*my_data);
t_bunny_response	refresh(void *my_data);
t_bunny_response	click(t_bunny_event_state            state,
			      t_bunny_mousebutton            button,
			      void                           *my_data);
t_bunny_response	mouse(t_bunny_position	*relativ,
			      void		*my_data);
void			init_menu(t_data *data);
void			delete_sound(t_data *data);
void			music_vol(t_data *data);
void			effect_vol(t_data *data);
void			handler_click_page1(t_data *data);
void			handler_click_page2(t_data *data);
void			handler_click2(t_data *data);
int			handler_click(t_data *data);
void			button_fight(t_data *data);
void			button_options(t_data *data);
void			button_credits(t_data *data);
void			display_button(t_data *data);
void			load_screen(t_data *data);
void			show_mouse(t_data *data);
void			show_credit(t_data *data,
				    t_bunny_position pos);
void			show_options(t_data *data);
void			show_wesh(t_data *data);
void			tektranspa(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color);
void			fill(t_bunny_pixelarray *pix,
			     t_color *color);
int			check_textures(t_data *data);
void			load_textures2(t_data *data);
int			load_textures(t_data *data);
void			handler_click4_page2(t_data *data);
void   			handler_click3_page2(t_data *data);
void   			handler_click2_page2(t_data *data);
void   			volume_music2(t_data		*data,
				      t_bunny_position	pos);
void   			volume_music(t_data		*data,
				     t_bunny_position	pos);
void   			volume_effect2(t_data		*data,
				       t_bunny_position	pos);
void   			volume_effect(t_data		*data,
				      t_bunny_position	pos);

#endif /* !GRAPH_H_ */
