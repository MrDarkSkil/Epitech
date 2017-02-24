/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Sun Mar 27 16:01:00 2016 Eric DESCHODT
*/

#include "corewar.h"

void		free_all(t_data *data)
{
  if (data->pix != NULL)
    bunny_delete_clipable(&data->pix->clipable);
  if (data->music != NULL)
    bunny_delete_sound(&data->music->sound);
  if (data->sko != NULL)
    bunny_delete_sound(&data->sko->sound);
  if (data->eko != NULL)
    bunny_delete_sound(&data->eko->sound);
  free_texture(data->back);
  free_texture(data->logo);
  free_texture(data->ko);
}

int		main(int ac, char **av)
{
  unsigned char	board[2][MEM_SIZE];
  t_vm		*vm;
  t_dlist	*list;
  t_dlist	*list_s;
  t_data	data;

  if (ac < 2 || start_graph(&data) == -1)
    return (usage());
  list = NULL;
  list_s = NULL;
  list = new_list(list);
  list_s = new_list(list_s);
  init_board(board);
  vm = NULL;
  vm = new_vm(vm);
  fill_list(list, av);
  start_game(list, vm, &data, board);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(key);
  bunny_loop(data.win, 60, &data);
  bunny_set_loop_main_function(endloop);
  bunny_loop(data.win, 60, &data);
  bunny_stop(data.win);
  free_all(&data);
  return (0);
}
